#include "Torpedo_interface.hpp"

#include <iostream>

Torpedo_interface::Torpedo_interface(int x, int y, int w, int h, function<void()> f, int size_x, int size_y, bool autoscale)
        :Widget(x,y,w,h),_f(f),_cell_piece_w(size_x),_cell_piece_h(size_y)
{
    _is_focusable=false;
    _focusable=false;



    _grid_color.set_color(WHITE);
    _gridbg_color.set_color(BLUE);
    _text_color.set_color(WHITE);
    _live_color.set_color(GREEN);
    _damaged_color.set_color(YELOW);
    _destroyed_color.set_color(RED);
    _sinked_color.set_color(DGRAY);

    if(autoscale){
        _h=2*(_w+_text_size);
    }
    //cout<<_w<<"\t"<<_h<<endl<<endl;

    _h_offset=_h/2;

    _table_x=_x+_text_size;
    _table_y=_y+2*_text_size;
    _table_w=_x+_w-_table_x;
    _table_h=_y+_h/2-_table_y;

    //cout<<_table_x<<"\t"<<_table_y<<endl<<_table_w<<"\t"<<_table_h<<endl;

    for(int i=0;i<_cell_piece_w;i++){
        _interval_w.push_back({_table_x+i*(_table_w/_cell_piece_w),_table_x+(i+1)*(_table_w/_cell_piece_w)-1});
    }
    for(int i=0;i<_cell_piece_h;i++){
        _interval_h.push_back({_table_y+i*(_table_h/_cell_piece_h),_table_y+(i+1)*(_table_h/_cell_piece_h)-1});
    }

    for(int i=0;i<_interval_w.size();i++){
        cout<<_interval_w[i].first<<"\t"<<_interval_w[i].second<<endl;
    }
    cout<<endl<<endl;

    for(int i=0;i<_interval_h.size();i++){
        cout<<_interval_h[i].first<<"\t"<<_interval_h[i].second<<endl;
    }

}

void Torpedo_interface::draw() const
{
    gout<<color(255,0,0)
        <<move_to(_x,_y)
        <<box_to(_x+_w,_y+_h);

    //cout<<_interval_w[-1].second<<"\t"<<_interval_h[-1].second<<endl;
    gout<<color(_gridbg_color.get_r(),_gridbg_color.get_g(),_gridbg_color.get_b())
        <<move_to(_interval_w[0].first,_interval_h[0].first)
        <<box_to(_interval_w.back().second,_interval_h.back().second);

    gout<<color(_gridbg_color.get_r(),_gridbg_color.get_g(),_gridbg_color.get_b())
        <<move_to(_interval_w[0].first,_h_offset+_interval_h[0].first)
        <<box_to(_interval_w.back().second,_h_offset+_interval_h.back().second);

    gout<<color(_grid_color.get_r(),_grid_color.get_g(),_grid_color.get_b());
    for(size_t i=0;i<_interval_w.size();i++){
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
    for(size_t i=0;i<_interval_h.size();i++){
        gout<<move_to(_interval_w[0].first,_interval_h[i].first)
            <<line_to(_interval_w.back().second,_interval_h[i].first)
            <<move_to(_interval_w[0].first,_h_offset+_interval_h[i].first)
            <<line_to(_interval_w.back().second,_h_offset+_interval_h[i].first);
    }
    gout<<move_to(_interval_w[0].first,_interval_h.back().second+1)
        <<line_to(_interval_w.back().second+1,_interval_h.back().second+1)
        <<move_to(_interval_w[0].first,_h_offset+_interval_h.back().second+1)
        <<line_to(_interval_w.back().second+1,_h_offset+_interval_h.back().second+1);

}

void Torpedo_interface::handle(genv::event ev)
{

}
