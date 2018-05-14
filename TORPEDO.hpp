#ifndef TORPEDO_HPP_INCLUDED
#define TORPEDO_HPP_INCLUDED

#include "Window.hpp"
#include "Torpedo_interface.hpp"
#include "GameMaster.hpp"

class TORPEDO: public Window
{
private:
    int XX, YY;                                                     ///ablak mérete
    int _game_w, _game_h;                                           ///játéktér celláinak száma

    GameMaster* _game;                                              ///a játékot kezelõ osztály

    Torpedo_interface* _interface;                                  ///játéktér widget
    Dropdown* _ammo;                                                ///lõszer választó
    Dropdown* _ships;                                               ///hajó választó

    size_t _ammo_type_count, _ship_type_count;                      ///a dropdownok hossza
public:
    TORPEDO(int xx, int yy, int w, int h);

    void choose_ship()                                              ///jelenleg kivélasztott hajó változtatása
    {
        _game->set_ship(_ships->get_text());
    }
    void choose_ammo()                                              ///jelenleg kivélasztott lõszer változtatása
    {
        _game->set_ammo(_ammo->get_text());
    }
    void click()                                                    ///kattintás a widgetre
    {
        _game->click(_interface->get_click_coord().first,
                     _interface->get_click_coord().second);
    }
    virtual void custom(event ev);

    void gamemode_change();                                         ///aktív legördülõ választása

    void cell_change();
};

#endif // TORPEDO_HPP_INCLUDED
