#include "Widget.hpp"

using namespace std;
using namespace genv;

Widget::Widget(int x, int y, int w, int h)
    : _x(x), _y(y), _w(w), _h(h), _wbig(0), _hbig(0),_is_focusable(true), _selected(false), _big(false), _active(true), _visible(true), _focusable(true)
{
    _frame.set_color(WHITE);
    _bground.set_color(BLACK);
    _figure.set_color(WHITE);
}

bool Widget::selected(int mouse_x, int mouse_y) const
{
    if(!_big)
    {
        return (mouse_x>_x && mouse_x<_x+_w && mouse_y>_y && mouse_y<_y+_h);
    }
    else
    {
        return (mouse_x>_x && mouse_x<_x+_wbig && mouse_y>_y && mouse_y<_y+_hbig);
    }
}

void Widget::set_selected(bool b)
{
    _selected=b;
}
