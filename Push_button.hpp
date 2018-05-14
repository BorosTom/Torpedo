#ifndef PUSH_BUTTON_HPP_INCLUDED
#define PUSH_BUTTON_HPP_INCLUDED

#include "Widget.hpp"

//#include <iostream>

class Push_button :public Widget
{
protected:
    string _label;
public:
    Push_button(int x, int y, int w, int h, string str):Widget(x,y,w,h),_label(str) {};
    virtual void draw() const override;
    virtual void handle(event ev) override;
    virtual string get_value() const override
    {
        return "";
    }
    virtual void action()=0;
};


#endif // PUSH_BUTTON_HPP_INCLUDED
