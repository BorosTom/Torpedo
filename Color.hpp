#ifndef COLOR_HPP_INCLUDED
#define COLOR_HPP_INCLUDED

#include <time.h>
#include <cstdlib>

enum col {RED,GREEN,BLUE,BLACK,WHITE,YELOW,MAGENTA,LBLUE,LGRAY,DGRAY,RND};

struct Color
{
    double _r,_g,_b;

    Color():_r(255),_g(255),_b(255) {}
    Color(double r, double g, double b):_r(r),_g(g),_b(b) {}
    void set_color(col c);
    Color(col c)
    {
        set_color(c);
    }
    double get_r() const
    {
        return _r;
    }
    double get_g() const
    {
        return _g;
    }
    double get_b() const
    {
        return _b;
    }
};


#endif // COLOR_HPP_INCLUDED
