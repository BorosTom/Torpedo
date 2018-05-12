#include "TORPEDO.hpp"

TORPEDO::TORPEDO(int xx, int yy, int w, int h):Window(xx,yy), _game_w(w),_game_h(h)
{
    _game=new GameMaster(w,h);

    _interface=new Torpedo_interface(10,10,300,-1,[this](){this->click();},w,h);
    _ships=new Dropdown(330,10,100,50,_game->get_ships(),3,[this](){this->choose_ship();});
    _ammo=new Dropdown(330,10,100,50,_game->get_ammo(),3,[this](){this->choose_ammo();});

    add_widget(_interface);
    add_widget(_ships);
    add_widget(_ammo);
}
