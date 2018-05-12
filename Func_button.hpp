#ifndef FUNC_BUTTON_HPP_INCLUDED
#define FUNC_BUTTON_HPP_INCLUDED

#include <functional>
#include "Push_button.hpp"

class Func_button :public Push_button{
protected:
    function<void()> _f;
public:
    Func_button(int x, int y, int w, int h, string str, function<void()> f):Push_button(x,y,w,h,str),_f(f){}
    virtual void action();

};


#endif // FUNC_BUTTON_HPP_INCLUDED
