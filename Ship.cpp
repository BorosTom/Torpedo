#include "Ship.hpp"

Ship::Ship(int x, int y, int w, int h, int armor)
    :_cell_x(x),_cell_y(y),_cell_w(w),_cell_h(h),_armor(armor),_crit(3),_lives(x*y),_live(true)
{
    ///hajó elemek elhelyezése
    for(int i=0; i<_cell_w; i++)
    {
        _ship_panels.push_back(vector<int> {});
        for(int j=0; j<_cell_h; j++)
        {
            _ship_panels[i].push_back(_armor);
        }
    }
}

void Ship::hit(int x, int y, int dmg)
{
    if(_live)
    {
        ///sérülés
        if(_ship_panels[x][y]>0){
            _ship_panels[x][y]-=dmg;
        }
        ///elem elpusztulás
        if(_ship_panels[x][y]<0)
        {
            _lives--;
        }
        ///kritikus találat
        if(_ship_panels[x][y]<=0-_crit)
        {
            _lives=0;
            _live=false;
            for(int i=0; i<_cell_w; i++)
            {
                _ship_panels.push_back(vector<int> {});
                for(int j=0; j<_cell_h; j++)
                {
                    _ship_panels[i].push_back(0);
                }
            }
        }
        ///elsüllyedés
        if(_lives<=0)
        {
            _live=false;
        }
    }
}

int Ship::get_armor(int x, int y)
{
    return _ship_panels[x][y];
}
