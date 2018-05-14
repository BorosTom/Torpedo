#ifndef TEXTEDITOR_HPP_INCLUDED
#define TEXTEDITOR_HPP_INCLUDED

#include <string>
#include "Widget.hpp"

using namespace std;
using namespace genv;

class TextEditor :public Widget
{
protected:
    string _str;
    double _cursor_x;
public:

    TextEditor(int x,int y,int w,int h);
    virtual void draw() const override;
    virtual void handle(event ev) override;
    virtual string get_text() const
    {
        return _str;
    }
    virtual string get_value() const override{
        return tostring(_str);
    }
};

#endif // TEXTEDITOR_HPP_INCLUDED
