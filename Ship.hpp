#ifndef SHIP_HPP_INCLUDED
#define SHIP_HPP_INCLUDED

#include <vector>



//enum hit_type{hit_destroyed,hit_notdestroyed,hit_miss};

using namespace std;

class Ship
{
    int _cell_x, _cell_y, _cell_w, _cell_h;                         ///poz�ci� �s m�ret cell�ban
    int _armor, _crit, _lives;                                      ///a haj� elemek �lete, a kritikus sebz�s k�sz�be �s a m�k�d� elemek sz�ma
    vector<vector<int> > _ship_panels;                              ///a haj� elemek elhelyezked�se �s �lete
    bool _live;                                                     ///a haj� �l-e m�g

public:
    Ship(int x, int y, int w, int h, int armor=1);

    virtual void hit(int x, int y, int dmg=1);                      ///haj� eltal�l�sa

    bool get_live()
    {
        return _live;   ///els�llyedt-e
    }
    int get_armor(int x, int y);                                    ///elem �lete

    /*bool valid_coordinates(int x, int y){
        return x>_ship_x && x<_ship_x+_ship_w && y>_ship_y && y<_ship_y+_ship_h;
    }*/
};

#endif // SHIP_HPP_INCLUDED
