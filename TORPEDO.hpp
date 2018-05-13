#ifndef TORPEDO_HPP_INCLUDED
#define TORPEDO_HPP_INCLUDED

#include "Window.hpp"
#include "Torpedo_interface.hpp"
#include "GameMaster.hpp"

class TORPEDO: public Window{
private:
    int XX, YY;                                                     ///ablak mérete
    int _game_w, _game_h;                                           ///játéktér celláinak száma

    GameMaster* _game;                                              ///a játékot kezelõ osztály

    Torpedo_interface* _interface;                                  ///játéktér widget
    Dropdown* _ammo;                                                ///lõszer választó
    Dropdown* _ships;                                               ///hajó választó


public:
    TORPEDO(int xx, int yy, int w, int h);

    void choose_ship(){}                                            ///jelenleg kivélasztott hajó változtatása
    void choose_ammo(){}                                            ///jelenleg kivélasztott lõszer változtatása
    void click(){                                                   ///kattintás a widgetre
        _game->click(_interface->get_click_coord().first,
                     _interface->get_click_coord().second);
    }


};

#endif // TORPEDO_HPP_INCLUDED
