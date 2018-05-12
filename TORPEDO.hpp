#ifndef TORPEDO_HPP_INCLUDED
#define TORPEDO_HPP_INCLUDED

#include "Window.hpp"
#include "Torpedo_interface.hpp"
#include "GameMaster.hpp"

class TORPEDO: public Window{
private:
    int XX, YY, _game_w, _game_h;

    GameMaster* _game;

    Torpedo_interface* _interface;
    Dropdown* _ammo;
    Dropdown* _ships;


public:
    TORPEDO(int xx, int yy, int w, int h);

    void choose_ship(){}
    void choose_ammo(){}
    void click(){}


};

#endif // TORPEDO_HPP_INCLUDED
