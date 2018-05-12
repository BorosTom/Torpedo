#include "Misc.hpp"

using namespace std;
using namespace genv;

void cls(int xx, int yy,Color col)
{
    gout<<move_to(0,0)<<color(col.get_r(),col.get_g(),col.get_b())<<box_to(xx-1,yy-1);
}

