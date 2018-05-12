#include "Push_button.hpp"

//#include <iostream>

void Push_button::draw() const
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
        gout<<color(_figure.get_r(),_figure.get_g(),_figure.get_b())
            <<move_to(_x+_w/2-gout.twidth(_label)/2,_y+_h/2+gout.cascent()/2)
            <<text(_label);
    }
}

void Push_button::handle(event ev)
{
    //cout<<"asd"<<endl;
    if(_active)
    {
        if(_selected && ev.type==ev_key && ev.keycode==key_enter)
        {
            action();
        }
        if(_selected && ev.type==ev_mouse && ev.button==btn_left)
        {
            action();
        }
    }
}

