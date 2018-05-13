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
    int _map_w, _map_h;                                                                             ///játéktér mérete cellában
    vector<vector<pair<Ship*,bool> > > _player1_own, _player1_enemy, _player2_own, _player2_enemy;  ///a játékosok flottái
    gamestates _state;                                                                              ///a játék állapota
    bool _singleplayer;                                                                             ///egyjátékos mód-e

    ///elhelyezéshez sükséges adatok
    int _current_ship_x, _current_ship_y, _current_ship_w, _current_ship_h;                         ///a jelenleg elhelyezni kívánt hajó pozíciója és mérete
    vector<pair<int,int> > _available_positions;                                                    ///a lehetséges végpontok a hajó elheletéséhez
    bool _wait_for_direction;                                                                       ///van-e kezdeti pont

    ammo_type _current_ammo;                                                                        ///jelenlegi lőszertípus
    vector<string> _ammo= {"a","b","c"};                                                            ///lőszerek nevei
    vector<pair<int,int> > _pair_ships;                                                             ///hajók méretei
    vector<string> _str_ships;                                                                      ///hajók megnevezése

public:
    GameMaster(int w, int h, bool single=true);
    bool valid_coordinates(int x, int y);                                                           ///érvényes-e a hivatkozott cella
    void click(int x, int y);                                                                       ///kattintás egy adott cellára
    void deploy_fleet(int x, int y, vector<vector<pair<Ship*,bool> > >* table);                     ///flotta elhelyezése

    void set_current_ship_pos(int x, int y)                                                         ///jelenlegi hajó pozíciójának beállítása
    {
        _current_ship_x=x;
        _current_ship_y=y;
    }
    void set_current_ship_size(int w, int h)                                                        ///jelenlegi hajó méretének beállítása
    {
        _current_ship_w=w;
        _current_ship_h=h;
    }
    vector<string>* get_ammo()                                                                      ///lehetséges lőszerek neveinek lekérése
    {
        return &_ammo;
    }
    vector<string>* get_ships(){                                                                    ///lehetséges hajók méretének lekérése
        return &_str_ships;
    }
};

#endif // GAMEMASTER_HPP_INCLUDED
