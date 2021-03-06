#include "TORPEDO.hpp"

TORPEDO::TORPEDO(int xx, int yy, int w, int h):Window(xx,yy), _game_w(w),_game_h(h)
{
    _game=new GameMaster(w,h,[this]()
    {
        this->gamemode_change();
    },[this]()
    {
        this->cell_change();
    });

    _interface=new Torpedo_interface(10,10,300,-1,[this]()
    {
        this->click();
    },w,h);
    _ships=new Dropdown(330,10,100,50,_game->get_ships(),3,[this]()
    {
        this->choose_ship();
    });
    _ammo=new Dropdown(440,10,100,50,_game->get_ammo(),3,[this]()
    {
        this->choose_ammo();
    });

    add_widget(_interface);
    add_widget(_ships);
    add_widget(_ammo);

    _ship_type_count=_game->get_ships()->size();
    _ammo_type_count=_game->get_ammo()->size();

    gamemode_change();
}

void TORPEDO::custom(event ev)
{



    ///f�l�sleges elemek t�rl�se a leg�rd�l�kb�l
    //cout<<_game->get_ships()->size()<<"\t"<<_ship_type_count<<endl;
    if(_game->get_ships()->size()!=_ship_type_count)
    {
        _ships->erease_elements();
        for(size_t i=0; i<_game->get_ships()->size(); i++)
        {
            _ships->add_element(_game->get_ships()->operator[](i));
            //cout<<_ships->get_vec_size()<<"\t"<<_ship_type_count<<endl;
        }
    }
    if(_game->get_ammo()->size()!=_ammo_type_count)
    {
        _ammo->erease_elements();
        for(size_t i=0; i<_game->get_ammo()->size(); i++)
        {
            _ammo->add_element(_game->get_ammo()->operator[](i));
        }
    }

    ///
}

void TORPEDO::gamemode_change()
{
    if(_game->get_gamestate()==deploy1 || _game->get_gamestate()==deploy2)
    {
        _ammo->set_visible(false);
        _ships->set_visible(true);
    }
    else
    {
        _ammo->set_visible(true);
        _ships->set_visible(false);
    }


}


void TORPEDO::cell_change()
{
    if(_game->get_gamestate()==deploy1 || _game->get_gamestate()==deploy2){
        cell_state cs;
        if(_game->get_wait()){
            cs=damaged;
        }
        else{
            cs=ok;
        }
        _interface->set_cell_state(false,_game->get_changed_x(),_game->get_changed_y(),cs);
    }
    else{

    }

}
