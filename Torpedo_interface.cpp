#include "Torpedo_interface.hpp"

#include <iostream>

Torpedo_interface::Torpedo_interface(int x, int y, int w, int h, function<void()> f, int size_x, int size_y, bool autoscale)
    :Widget(x,y,w,h),_f(f),_cell_piece_w(size_x),_cell_piece_h(size_y),_click_x(-1),_click_y(-1)
{
    ///fókuszálható-e a widget
    //_is_focusable=false;
    //_focusable=false;
    //_active=true;

    ///színek alap beállításai
    _grid_color.set_color(WHITE);
    _gridbg_color.set_color(BLUE);
    _text_color.set_color(WHITE);
    _live_color.set_color(GREEN);
    _damaged_color.set_color(YELOW);
    _destroyed_color.set_color(RED);
    _sinked_color.set_color(DGRAY);

    ///widget automata méretezése téglalap alakú pályához
    if(autoscale)
    {
        _h=2*(_w+_text_size);
    }
    //cout<<_w<<"\t"<<_h<<endl<<endl;

    ///eltolás beállítása
    _h_offset=_h/2;

    ///táblák pozícióinak és méretének kiszámítása
    _table_x=_x+_text_size;
    _table_y=_y+2*_text_size;
    _table_w=_x+_w-_table_x;
    _table_h=_y+_h/2-_table_y;

    //cout<<_table_x<<"\t"<<_table_y<<endl<<_table_w<<"\t"<<_table_h<<endl;

    ///intervallumok beállítása
    for(int i=0; i<_cell_piece_w; i++)
    {
        _interval_w.push_back({_table_x+i*(_table_w/_cell_piece_w),_table_x+(i+1)*(_table_w/_cell_piece_w)-1});
    }
    for(int i=0; i<_cell_piece_h; i++)
    {
        _interval_h.push_back({_table_y+i*(_table_h/_cell_piece_h),_table_y+(i+1)*(_table_h/_cell_piece_h)-1});
    }

    ///a cellák állapotának megállapítása
    for(int i=0; i<_cell_piece_w; i++)
    {
        _table_own.push_back({});
        for(int j=0; j<_cell_piece_h; j++)
        {
            _table_own[i].push_back(emptycell);
        }
    }
    for(int i=0; i<_cell_piece_w; i++)
    {
        _table_enemy.push_back({});
        for(int j=0; j<_cell_piece_h; j++)
        {
            _table_enemy[i].push_back(emptycell);
        }
    }

    /*for(int i=0;i<_interval_w.size();i++){
        cout<<_interval_w[i].first<<"\t"<<_interval_w[i].second<<endl;
    }
    cout<<endl<<endl;

    for(int i=0;i<_interval_h.size();i++){
        cout<<_interval_h[i].first<<"\t"<<_interval_h[i].second<<endl;
    }*/

}

void Torpedo_interface::draw() const
{
    if(_visible)
    {
        ///háttér kirajzolása
        gout<<color(0,0,0)
            <<move_to(_x,_y)
            <<box_to(_x+_w,_y+_h);

        ///játéktér háttér kirajzolása
        //cout<<_interval_w[-1].second<<"\t"<<_interval_h[-1].second<<endl;
        gout<<color(_gridbg_color.get_r(),_gridbg_color.get_g(),_gridbg_color.get_b())
            <<move_to(_interval_w[0].first,_interval_h[0].first)
            <<box_to(_interval_w.back().second,_interval_h.back().second);

        gout<<color(_gridbg_color.get_r(),_gridbg_color.get_g(),_gridbg_color.get_b())
            <<move_to(_interval_w[0].first,_h_offset+_interval_h[0].first)
            <<box_to(_interval_w.back().second,_h_offset+_interval_h.back().second);

        ///rácsok kirajzolása
        gout<<color(_grid_color.get_r(),_grid_color.get_g(),_grid_color.get_b());
        for(size_t i=0; i<_interval_w.size(); i++)
        {
            gout<<move_to(_interval_w[i].first,_interval_h[0].first)
                <<line_to(_interval_w[i].first,_interval_h.back().second)
                <<move_to(_interval_w[i].first,_h_offset+_interval_h[0].first)
                <<line_to(_interval_w[i].first,_h_offset+_interval_h.back().second);
        }
        gout<<move_to(_interval_w.back().second+1,_interval_h[0].first)
            <<line_to(_interval_w.back().second+1,_interval_h.back().second+1)
            <<move_to(_interval_w.back().second+1,_h_offset+_interval_h[0].first)
            <<line_to(_interval_w.back().second+1,_h_offset+_interval_h.back().second+1);

        gout<<color(_grid_color.get_r(),_grid_color.get_g(),_grid_color.get_b());
        for(size_t i=0; i<_interval_h.size(); i++)
        {
            gout<<move_to(_interval_w[0].first,_interval_h[i].first)
                <<line_to(_interval_w.back().second,_interval_h[i].first)
                <<move_to(_interval_w[0].first,_h_offset+_interval_h[i].first)
                <<line_to(_interval_w.back().second,_h_offset+_interval_h[i].first);
        }
        gout<<move_to(_interval_w[0].first,_interval_h.back().second+1)
            <<line_to(_interval_w.back().second+1,_interval_h.back().second+1)
            <<move_to(_interval_w[0].first,_h_offset+_interval_h.back().second+1)
            <<line_to(_interval_w.back().second+1,_h_offset+_interval_h.back().second+1);

        ///feliratok kirajzolása
        gout<<color(_text_color.get_r(),_text_color.get_g(),_text_color.get_b())
            <<move_to(_x+(_w/2)-(gout.twidth("Own fleet")/2),_y+(_text_size/2)+(gout.cascent()/2))
            <<text("Own fleet")
            <<move_to(_x+(_w/2)-(gout.twidth("Enemy fleet")/2),_y+_h_offset+(_text_size/2)+(gout.cascent()/2))
            <<text("Enemy fleet");
        for(size_t i=0; i<_interval_w.size(); i++)
        {
            gout<<move_to(_interval_w[i].first+(_interval_w[i].second-_interval_w[i].first)/2-gout.twidth(tostring(char(65+i)))/2,_y+_text_size+_text_size/2+gout.cascent()/2)
                <<text(tostring(char(65+i)))
                <<move_to(_interval_w[i].first+(_interval_w[i].second-_interval_w[i].first)/2-gout.twidth(tostring(char(65+i)))/2,_y+_text_size+_text_size/2+gout.cascent()/2+_h_offset)
                <<text(tostring(char(65+i)));
        }
        for(size_t i=0; i<_interval_h.size(); i++)
        {
            gout<<move_to(_x+(_text_size/2)-(gout.twidth(tostring(i+1))/2),_interval_h[i].first+(_interval_h[i].second-_interval_h[i].first)/2+(gout.cascent()/2))
                <<text(tostring(i+1))
                <<move_to(_x+(_text_size/2)-(gout.twidth(tostring(i+1))/2),_h_offset+_interval_h[i].first+(_interval_h[i].second-_interval_h[i].first)/2+(gout.cascent()/2))
                <<text(tostring(i+1));
        }

        ///cellák kitöltése
        for(int i=0; i<_cell_piece_w; i++)
        {
            for(int j=0; j<_cell_piece_h; j++)
            {
                switch(_table_own[i][j])
                {
                case emptycell:
                    break;
                case miss:
                    draw_miss(i,j,false);
                    break;
                case ok:
                    draw_ok(i,j,false);
                    break;
                case damaged:
                    draw_damaged(i,j,false);
                    break;
                case destroyed:
                    draw_destroyed(i,j,false);
                    break;
                case sinked:
                    draw_sinked(i,j,false);
                    break;
                default:
                    break;
                }
                switch(_table_enemy[i][j])
                {
                case emptycell:
                    break;
                case miss:
                    draw_miss(i,j,true);
                    break;
                case ok:
                    draw_ok(i,j,true);
                    break;
                case damaged:
                    draw_damaged(i,j,true);
                    break;
                case destroyed:
                    draw_destroyed(i,j,true);
                    break;
                case sinked:
                    draw_sinked(i,j,true);
                    break;
                default:
                    break;
                }
            }
        }
    }
}

void Torpedo_interface::draw_miss(int i, int j, bool offset) const
{
    double off=0;
    if(offset)
    {
        off=_h_offset;
    }
    gout<<color(_sinked_color.get_r(),_sinked_color.get_g(),_sinked_color.get_b())
        <<move_to(_interval_w[i].first+1,off+_interval_h[j].first+1)
        <<line_to(_interval_w[i].second,off+_interval_h[j].second)
        <<move_to(_interval_w[i].second+1,off+_interval_h[j].first+1)
        <<line_to(_interval_w[i].first,off+_interval_h[j].second);
}
void Torpedo_interface::draw_ok(int i, int j, bool offset) const
{
    double off=0;
    if(offset)
    {
        off=_h_offset;
    }
    gout<<color(_live_color.get_r(),_live_color.get_g(),_live_color.get_b())
        <<move_to(_interval_w[i].first+1,off+_interval_h[j].first+1)
        <<box_to(_interval_w[i].second,off+_interval_h[j].second);
}
void Torpedo_interface::draw_damaged(int i, int j, bool offset) const
{
    double off=0;
    if(offset)
    {
        off=_h_offset;
    }
    gout<<color(_damaged_color.get_r(),_damaged_color.get_g(),_damaged_color.get_b())
        <<move_to(_interval_w[i].first+1,off+_interval_h[j].first+1)
        <<box_to(_interval_w[i].second,off+_interval_h[j].second);
}
void Torpedo_interface::draw_destroyed(int i, int j, bool offset) const
{
    double off=0;
    if(offset)
    {
        off=_h_offset;
    }
    gout<<color(_destroyed_color.get_r(),_destroyed_color.get_g(),_destroyed_color.get_b())
        <<move_to(_interval_w[i].first+1,off+_interval_h[j].first+1)
        <<box_to(_interval_w[i].second,off+_interval_h[j].second);
}
void Torpedo_interface::draw_sinked(int i, int j, bool offset) const
{
    double off=0;
    if(offset)
    {
        off=_h_offset;
    }
    gout<<color(_sinked_color.get_r(),_sinked_color.get_g(),_sinked_color.get_b())
        <<move_to(_interval_w[i].first+1,off+_interval_h[j].first+1)
        <<box_to(_interval_w[i].second,off+_interval_h[j].second);
}

void Torpedo_interface::set_cell_state(bool enemy, int x, int y, cell_state cs)
{
    if(!enemy)
    {
        _table_own[x][y]=cs;
    }
    else
    {
        _table_enemy[x][y]=cs;
    }
}

void Torpedo_interface::handle(genv::event ev)
{
    if(_active)
    {
        if(ev.type==ev_mouse && ev.button==btn_left)
        {
            for(int i=0; i<_cell_piece_w; i++)
            {
                for(int j=0; j<_cell_piece_h; j++)
                {
                    if(ev.pos_x>_interval_w[i].first && ev.pos_x<_interval_w[i].second && ev.pos_y>_interval_h[j].first && ev.pos_y<_interval_h[j].second)
                    {
                        _click_x=i;
                        _click_y=j;
                        _f();
                        _click_x=-1;
                        _click_y=-1;
                    }
                    else
                    {
                        if(ev.pos_x>_interval_w[i].first && ev.pos_x<_interval_w[i].second && ev.pos_y>_h_offset+_interval_h[j].first && ev.pos_y<_h_offset+_interval_h[j].second)
                        {
                            _click_x=i;
                            _click_y=j;
                            _f();
                            _click_x=-1;
                            _click_y=-1;
                        }
                    }
                }
            }
        }
    }
}
