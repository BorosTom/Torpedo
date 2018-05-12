#ifndef GAMEMASTER_HPP_INCLUDED
#define GAMEMASTER_HPP_INCLUDED

#include <vector>
#include <string>

#include "Ship.hpp"

enum gamestates {deploy1,deploy2,pl1,pl2};
enum ammo_type {torpedo,scan,pierce};

class GameMaster
{
private:
    int _map_w, _map_h;
    vector<vector<pair<Ship*,bool> > > _player1_own, _player1_enemy, _player2_own, _player2_enemy;
    gamestates _state;
    bool _singleplayer;

    ///elhelyezéshez sükséges adatok
    int _current_ship_x, _current_ship_y, _current_ship_w, _current_ship_h;
    vector<pair<int,int> > _available_positions;
    bool _wait_for_direction;

    ammo_type _current_ammo;
    vector<string> _ammo= {"a","b","c"};
    vector<pair<int,int> > _pair_ships;
    vector<string> _str_ships;

public:
    GameMaster(int w, int h, bool single=true);
    bool valid_coordinates(int x, int y);
    void click(int x, int y);
    void deploy_fleet(int x, int y, vector<vector<pair<Ship*,bool> > >* table);

    void set_current_ship_pos(int x, int y)
    {
        _current_ship_x=x;
        _current_ship_y=y;
    }
    void set_current_ship_size(int w, int h)
    {
        _current_ship_w=w;
        _current_ship_h=h;
    }
    vector<string>* get_ammo()
    {
        return &_ammo;
    }
    vector<string>* get_ships(){
        return &_str_ships;
    }
};

#endif // GAMEMASTER_HPP_INCLUDED
