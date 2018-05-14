#include "Dropdown.hpp"

//#include <iostream>

Dropdown::Dropdown(int x, int y, int w, int h, int p, function<void()> f)
    :Widget(x,y,w,h),_piece(p),_max_piece(p),_chosen(0),_highlighted(-1),_visible_from(0),_dropped(false),_f(f)
{
    _vec.push_back(_default);
    if(int(_vec.size())<_piece)
    {
        _piece=_vec.size();
    }
    _wbig=_w;
    _hbig=_h+(_piece)*_h;
}

Dropdown::Dropdown(int x, int y, int w, int h, vector<string>& v, int p, function<void()> f)
    :Widget(x,y,w,h),_piece(p),_max_piece(p),_chosen(0),_highlighted(-1),_visible_from(0),_dropped(false),_f(f)
{
    _vec.push_back(_default);
    for(size_t i=0; i<v.size(); i++)
    {
        _vec.push_back(v[i]);
    }
    if(int(_vec.size())<_piece)
    {
        _piece=_vec.size();
    }
    _wbig=_w;
    _hbig=_h+(_piece)*_h;
}

Dropdown::Dropdown(int x, int y, int w, int h, vector<string>* v, int p, function<void()> f)
    :Widget(x,y,w,h),_piece(p),_max_piece(p),_chosen(0),_highlighted(-1),_visible_from(0),_dropped(false),_f(f)
{
    _vec.push_back(_default);
    for(size_t i=0; i<v->size(); i++)
    {
        _vec.push_back(v->operator[](i));
    }
    if(int(_vec.size())<_piece)
    {
        _piece=_vec.size();
    }
    _wbig=_w;
    _hbig=_h+(_piece+1)*_h;
}

void Dropdown::set_selected(bool b)
{
    if(_active)
    {
        _selected=b;
        if(!b)
        {
            _big=false;
            _dropped=false;
            _highlighted=-1;
        }
    }
}

void Dropdown::draw() const
{
    if(_visible)
    {
        gout<<color(_frame.get_r(),_frame.get_g(),_frame.get_b())
            <<move_to(_x,_y)
            <<box_to(_x+_w,_y+_h);

        if(_selected)
        {
            gout<<color(_bground.get_r(),_bground.get_g(),_bground.get_b())
                <<move_to(_x+2,_y+2)
                <<box_to(_x+_w-2,_y+_h-2);
        }
        else
        {
            gout<<color(_bground.get_r(),_bground.get_g(),_bground.get_b())
                <<move_to(_x+1,_y+1)
                <<box_to(_x+_w-1,_y+_h-1);
        }

        gout<<color(_frame.get_r(),_frame.get_g(),_frame.get_b())
            <<move_to(_x+_w-_btn_w,_y)
            <<line_to(_x+_w-_btn_w,_y+_h)
            <<color(_figure.get_r(),_figure.get_g(),_figure.get_b())
            <<move_to(((_x+_w-_btn_w)+(_x+_w))/2-5,((_y)+(_y+_h))/2-5)
            <<line_to(((_x+_w-_btn_w)+(_x+_w))/2,((_y)+(_y+_h))/2+5)
            <<line_to(((_x+_w-_btn_w)+(_x+_w))/2+5,((_y)+(_y+_h))/2-5);

        gout<<color(_figure.get_r(),_figure.get_g(),_figure.get_b())
            <<move_to(_x+(_w-_btn_w)/2-gout.twidth(_vec[_chosen])/2,_y+_h/2+gout.cascent()/2)
            <<text(_vec[_chosen]);

        if(_dropped)
        {
            for(int i=0; i<_piece; i++)
            {
                gout<<color(_frame.get_r(),_frame.get_g(),_frame.get_b())
                    <<move_to(_x,_y+_h+i*_h)
                    <<box_to(_x+_w,_y+_h+(i+1)*_h);

                if(i==_highlighted)
                {
                    gout<<color(_bground.get_r(),_bground.get_g(),_bground.get_b())
                        <<move_to(_x+2,_y+_h+i*_h+2)
                        <<box_to(_x+_w-2,_y+_h+(i+1)*_h-2);
                }
                else
                {
                    gout<<color(_bground.get_r(),_bground.get_g(),_bground.get_b())
                        <<move_to(_x+1,_y+_h+i*_h+1)
                        <<box_to(_x+_w-1,_y+_h+(i+1)*_h-1);
                }

                gout<<color(_figure.get_r(),_figure.get_g(),_figure.get_b())
                    <<move_to(((_x)+(_x+_w))/2-gout.twidth(_vec[i])/2,((_y+_h+i*_h)+(_y+_h+(i+1)*_h))/2+gout.cascent()/2)
                    <<text(_vec[_visible_from+i]);
            }
        }
    }
}

void Dropdown::handle(event ev)
{
    //cout<<"asd"<<endl;
    if(_active)
    {
        if(_selected && _dropped && ev.type==ev_mouse)
        {
            for(int i=0; i<_piece; i++)
            {
                if(ev.pos_x>_x && ev.pos_x<_x+_w && ev.pos_y>_y+_h+i*_h && ev.pos_y<_y+_h+(i+1)*_h)
                {
                    _highlighted=i;
                }
            }
            if(ev.button==btn_wheelup)
            {
                if(_visible_from>0)
                {
                    _visible_from--;
                }
            }
            if(ev.button==btn_wheeldown)
            {
                if(_visible_from<(int(_vec.size())-_piece))
                {
                    _visible_from++;
                }
            }
        }

        if(_selected && _dropped && ev.type==ev_key)
        {
            if(_highlighted==-1)
            {
                _highlighted=0;
            }
            if(ev.keycode==key_up)
            {
                if(_highlighted==0)
                {
                    if(_visible_from>0)
                    {
                        _visible_from--;
                    }
                }
                else
                {
                    if(_highlighted>0)
                    {
                        _highlighted--;
                    }
                }
            }
            if(ev.keycode==key_down)
            {
                if(_highlighted==_piece-1)
                {
                    if(_visible_from<int(_vec.size())-_piece)
                    {
                        _visible_from++;
                    }
                }
                else
                {
                    if(_highlighted<_piece)
                    {
                        _highlighted++;
                    }
                }
            }
        }

        if(_selected && ((ev.type==ev_mouse && ev.button==btn_left) || (ev.type==ev_key && ev.keycode==key_enter)))
        {
            if(!_dropped)
            {
                _dropped=true;
                _big=true;
            }
            else
            {
                _dropped=false;
                _big=false;

                if(_highlighted!=-1)
                {
                    _chosen=_visible_from+_highlighted;
                    action();
                }
            }
        }
    }
}

void Dropdown::add_element(string str)
{
    _vec.push_back(str);
    if(int(_vec.size())<=_max_piece)
    {
        _piece=_vec.size();
    }
    _hbig=_h+(_piece)*_h;
    sort(_vec.begin(), _vec.end());
}

void Dropdown::delete_element(string str)
{
    string ch=_vec[_chosen];
    _chosen=0;
    vector<string> tmp{_default};
    for(int i=1; i<int(_vec.size()); i++)
    {
        if(_vec[i]!=str)
        {
            tmp.push_back(_vec[i]);
            if(_vec[i]==ch)
            {
                _chosen=int(tmp.size()-1);
            }
        }
        else if(_visible_from>0 && _visible_from<i && _visible_from+_piece>i)
        {
            _visible_from--;
        }
    }
    _vec=tmp;
    if(int(_vec.size())<_piece)
    {
        _piece=_vec.size();
        _highlighted=0;
    }
    _hbig=_h+(_piece)*_h;
}

void Dropdown::erease_elements()
{
    while(_vec.size()>1){
        delete_element(_vec.back());
    }
    //cout<<_vec.size()<<endl;
}
