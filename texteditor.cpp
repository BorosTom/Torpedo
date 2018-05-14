#include "texteditor.hpp"


TextEditor::TextEditor(int x,int y,int w,int h):Widget(x,y,w,h),_str(""),_cursor_x(_x+5) {}

void TextEditor::draw() const
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
            <<move_to(_x+3,_y+_h/2+gout.cascent()/2)
            <<text(_str);

        if(_selected)
        {
            gout<<move_to(_cursor_x,_y+_h/2+gout.cascent()/2)
                <<line_to(_cursor_x,_y+_h/2-gout.cascent()/2);
        }
    }
}

void TextEditor::handle(event ev)
{
    if(_active)
    {
        if(_selected && ev.type==ev_key  && ((ev.keycode>42 && ev.keycode<300) || ev.keycode==32) && _cursor_x<_x+_w-10)
        {
            _str+=char(ev.keycode);
            _cursor_x=_x+3+gout.twidth(_str)+2;
        }
        if(_selected && _str.size()>0 && ev.type==ev_key && ev.keycode==8)
        {
            _str.pop_back();
            _cursor_x=_x+3+gout.twidth(_str)+2;
        }
    }
}
