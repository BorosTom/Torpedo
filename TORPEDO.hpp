#ifndef TORPEDO_HPP_INCLUDED
#define TORPEDO_HPP_INCLUDED

#include "Window.hpp"
#include "Torpedo_interface.hpp"
#include "GameMaster.hpp"

class TORPEDO: public Window{
private:
    int XX, YY;                                                     ///ablak m�rete
    int _game_w, _game_h;                                           ///j�t�kt�r cell�inak sz�ma

    GameMaster* _game;                                              ///a j�t�kot kezel� oszt�ly

    Torpedo_interface* _interface;                                  ///j�t�kt�r widget
    Dropdown* _ammo;                                                ///l�szer v�laszt�
    Dropdown* _ships;                                               ///haj� v�laszt�


public:
    TORPEDO(int xx, int yy, int w, int h);

    void choose_ship(){}                                            ///jelenleg kiv�lasztott haj� v�ltoztat�sa
    void choose_ammo(){}                                            ///jelenleg kiv�lasztott l�szer v�ltoztat�sa
    void click(){                                                   ///kattint�s a widgetre
        _game->click(_interface->get_click_coord().first,
                     _interface->get_click_coord().second);
    }


};

#endif // TORPEDO_HPP_INCLUDED
