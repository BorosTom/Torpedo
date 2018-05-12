#ifndef SHIP_HPP_INCLUDED
#define SHIP_HPP_INCLUDED

#include <vector>



//enum hit_type{hit_destroyed,hit_notdestroyed,hit_miss};

using namespace std;

class Ship{
    int _cell_x, _cell_y, _cell_w, _cell_h, _armor, _crit, _lives;
    vector<vector<int> > _ship_panels;
    bool _live;

public:
    Ship(int x, int y, int w, int h, int armor=1);

    virtual void hit(int x, int y, int dmg=1);

    bool get_live(){return _live;}
    int get_armor(int x, int y);

    /*bool valid_coordinates(int x, int y){
        return x>_ship_x && x<_ship_x+_ship_w && y>_ship_y && y<_ship_y+_ship_h;
    }*/
};

#endif // SHIP_HPP_INCLUDED
