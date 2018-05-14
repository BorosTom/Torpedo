#include "GameMaster.hpp"
#include "Misc.hpp"


GameMaster::GameMaster(int w, int h, function<void()> gc, function<void()> cc)
    :_map_w(w),_map_h(h),_state(deploy1),_current_ship_x(0), _current_ship_y(0),_current_ship_w(0),
     _current_ship_h(0),_wait_for_direction(false),_gamestate_change(gc),_cell_change(cc)
{
    ///játék táblák létrehozása
    for(int i=0; i<_map_w; i++)
    {
        _player1_own.push_back({});
        _player1_enemy.push_back({});
        _player2_own.push_back({});
        _player2_enemy.push_back({});
        for(int j=0; j<_map_h; j++)
        {
            _player1_own[i].push_back({nullptr,false});
            _player1_enemy[i].push_back({nullptr,false});
            _player2_own[i].push_back({nullptr,false});
            _player2_enemy[i].push_back({nullptr,false});
        }
    }
    ///hajó méretek beállítása
    for(int i=0; i<4; i++)
    {
        _pair_ships_pl1.push_back({{1,i+1},tostring(1)+"x"+tostring(i+1)});
        //cout<<tostring(1)+"x"+tostring(i+1)<<endl;
        _pair_ships_pl2.push_back({{1,i+1},tostring(1)+"x"+tostring(i+1)});
    }

    for(size_t i=0; i<_pair_ships_pl1.size(); i++)
    {
        _str_ships.push_back(_pair_ships_pl1[i].second);
    }
    for(size_t i=0; i<_ammo.size(); i++)
    {
        _str_ammo.push_back(_ammo[i].second);
    }
}

bool GameMaster::valid_coordinates(int x, int y)
{
    return x>=0 && y>=0 && x<_map_w && y<_map_h;
}

void GameMaster::click(int x, int y)
{
    //cout<<x<<"\t"<<y<<endl;
    switch(_state)
    {
    case deploy1:
        deploy_fleet(x,y);
        if(_pair_ships_pl1.size()<=0)
        {
            _state=deploy2;
            _gamestate_change();
        }
        break;
    case deploy2:
        deploy_fleet(x,y);
        if(_pair_ships_pl2.size()<=0)
        {
            _state=pl1;
            _gamestate_change();
        }
        break;
    case pl1:

        break;
    case pl2:

        break;
    default:

        break;
    }
}

void GameMaster::deploy_fleet(int x, int y)
{
    if(_state==deploy1)
    {
        if(!_wait_for_direction)
        {
            _current_ship_x=x;
            _current_ship_y=y;
            _wait_for_direction=true;
            _cell_change();
        }
        else
        {

        }
    }
    else
    {

    }
}

void GameMaster::set_ammo(string str)
{
    _current_ammo=noammo;
    for(size_t i=0; i<_ammo.size(); i++)
    {
        if(str.compare(_ammo[i].second)==0)
        {
            _current_ammo=_ammo[i].first;
        }
    }
}

void GameMaster::set_ship(string str)
{
    set_current_ship_size(-1,-1);
    for(size_t i=0; i<_str_ships.size(); i++)
    {

        if(str.compare(_pair_ships_pl1[i].second)==0)
        {
            //cout<<str<<"\t"<<_pair_ships_pl1[i].second<<endl;
            set_current_ship_size(_pair_ships_pl1[i].first.first,_pair_ships_pl1[i].first.second);
            //cout<<_pair_ships_pl1[i].first.first<<"\t"<<_pair_ships_pl1[i].first.second<<endl;
        }
    }
    //cout<<_current_ship_w<<"\t"<<_current_ship_h<<endl;
}
