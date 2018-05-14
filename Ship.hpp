#ifndef SHIP_HPP_INCLUDED
#define SHIP_HPP_INCLUDED

#include <vector>



//enum hit_type{hit_destroyed,hit_notdestroyed,hit_miss};

using namespace std;

class Ship
{
    int _cell_x, _cell_y, _cell_w, _cell_h;                         ///pozíció és méret cellában
    int _armor, _crit, _lives;                                      ///a hajó elemek élete, a kritikus sebzés küszöbe és a mõködõ elemek száma
    vector<vector<int> > _ship_panels;                              ///a hajó elemek elhelyezkedése és élete
    bool _live;                                                     ///a hajó él-e még

public:
    Ship(int x, int y, int w, int h, int armor=1);

    virtual void hit(int x, int y, int dmg=1);                      ///hajó eltalálása

    bool get_live()
    {
        return _live;   ///elsüllyedt-e
    }
    int get_armor(int x, int y);                                    ///elem élete

    /*bool valid_coordinates(int x, int y){
        return x>_ship_x && x<_ship_x+_ship_w && y>_ship_y && y<_ship_y+_ship_h;
    }*/
};

#endif // SHIP_HPP_INCLUDED
