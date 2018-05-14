#ifndef MISC_HPP_INCLUDED
#define MISC_HPP_INCLUDED

#include <string>
#include <sstream>
#include "graphics.hpp"
#include "Color.hpp"

using namespace std;
using namespace genv;

template<class T>
string tostring(T val)
{
    stringstream ss;
    ss<<val;
    return ss.str();
}

void cls(int xx, int yy, Color col);


#endif // MISC_HPP_INCLUDED
