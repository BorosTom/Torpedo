#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include <functional>
#include <vector>
#include <fstream>

#include "graphics.hpp"
#include "Widget.hpp"
#include "Checkbox.hpp"
#include "StaticText.hpp"
#include "texteditor.hpp"
#include "Num.hpp"
#include "Window.hpp"
#include "Dropdown.hpp"
#include "Password.hpp"
#include "Func_button.hpp"

//#include <iostream>


using namespace std;
using namespace genv;

class Window
{
protected:
    vector<Widget*> _vec;
    double _xx,_yy;
    int focus;
public:
    Window(double xx, double yy):_xx(xx),_yy(yy),focus(-1){gout.open(_xx,_yy);}
    virtual void event_loop();
    virtual void add_widget(Widget* w)
    {
        _vec.push_back(w);
    };
    virtual void custom(event ev){}
};


#endif // WINDOW_HPP_INCLUDED
