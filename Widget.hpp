#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

#include "graphics.hpp"
#include "Color.hpp"
#include "Misc.hpp"

//#include<string>

using namespace std;
using namespace genv;

class Widget
{
protected:
    int _x, _y, _w, _h, _wbig, _hbig;
    bool _is_focusable, _selected, _big, _active, _visible, _focusable;
    Color _frame, _bground, _figure;
public:
    Widget(int x, int y, int w, int h);
    virtual bool selected(int mouse_x, int mouse_y)const;
    virtual void draw() const= 0;
    virtual void handle(genv::event ev) = 0;
    virtual void set_selected(bool b);
    void set_frame_color(col c)
    {
        _frame.set_color(c);
    }
    void set_bground_color(col c)
    {
        _bground.set_color(c);
    }
    void set_figure_color(col c)
    {
        _figure.set_color(c);
    }
    virtual string get_value() const =0;

    void set_active(bool b)
    {
        _active=b;
    }
    bool get_active()
    {
        return _active;
    }
    virtual void set_visible(bool b)
    {
        _visible=b;
        _active=b;
        if(_is_focusable)
        {
            _focusable=b;
        }
    }
    bool get_visible()
    {
        return _visible;
    }
    bool get_focusable() const
    {
        return _focusable;
    }


    ///______TEST______

    //virtual void add_element(string str){};
    //virtual void delete_element(string str){};

};

#endif // WIDGET_HPP_INCLUDED
