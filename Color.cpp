#include "Color.hpp"

void Color::set_color(col c)
{

    switch(c)
    {
    case RED:
        _r=255;
        _g=_b=0;
        break;
    case GREEN:
        _g=255;
        _r=_b=0;
        break;
    case BLUE:
        _b=255;
        _r=_g=0;
        break;
    case BLACK:
        _r=_g=_b=0;
        break;
    case WHITE:
        _r=_g=_b=255;
        break;
    case YELOW:
        _r=_g=255;
        _b=0;
        break;
    case MAGENTA:
        _r=_b=255;
        _g=0;
        break;
    case LBLUE:
        _r=0;
        _g=_b=255;
        break;
    case LGRAY:
        _r=_g=_b=200;
        break;
    case DGRAY:
        _r=_g=_b=100;
        break;
    case RND:
        _r=rand() %255;
        _g=rand() %255;
        _b=rand() %255;
        break;
    default:
        _r=_g=_b=0;
        break;
    }
}
