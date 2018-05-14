#ifndef DROPDOWN_HPP_INCLUDED
#define DROPDOWN_HPP_INCLUDED

#include <string>
#include <vector>
#include <algorithm>
#include <functional>

#include <iostream>
#include "Widget.hpp"

class Dropdown: public Widget
{
protected:
    vector<string> _vec;
    int _piece,_max_piece,_chosen,_highlighted,_visible_from;
    bool _dropped;
    double _btn_w=20;
    string _default="---";

    function<void()> _f;
public:

    Dropdown(int x, int y, int w, int h, int p=3, function<void()> f=0);
    Dropdown(int x, int y, int w, int h, vector<string>& v, int p=3, function<void()> f=0);
    Dropdown(int x, int y, int w, int h, vector<string>* v, int p=3, function<void()> f=0);

    virtual string get_default()
    {
        return _default;
    }
    virtual string get_text() const
    {
        return _vec[_chosen];
    }
    void set_selected(bool b) override;
    virtual void draw() const override;
    virtual void handle(event ev) override;
    virtual string get_value() const override
    {
        return _vec[_chosen];
    }
    virtual void add_element(string str);
    virtual void delete_element(string str);

    virtual void action()
    {
        if(_f!=0)
        {
            _f();
        }
    }
    int get_vec_size()
    {
        return _vec.size();
    }
    void erease_elements();

};


#endif // DROPDOWN_HPP_INCLUDED
