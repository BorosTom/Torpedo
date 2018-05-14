#ifndef GAMEMASTER_HPP_INCLUDED
#define GAMEMASTER_HPP_INCLUDED

#include <vector>
#include <string>
#include <iostream>

#include "Ship.hpp"

enum gamestates {deploy1,deploy2,pl1,pl2};
enum ammo_type {noammo,torpedo,scann,pierce};

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
    vector<pair<ammo_type,string> > _ammo= {{torpedo,"Torpedo"},{scann,"Scann"},{pierce,"Pierce"}}; ///lőszerek
    vector<string> _str_ammo;                                                                       ///lőszerek nevei
    vector<pair<pair<int,int>,string> > _pair_ships_pl1, _pair_ships_pl2;                           ///hajók méretei
    vector<string> _str_ships;                                                                      ///hajók megnevezése

public:
    GameMaster(int w, int h, bool single=true);
    bool valid_coordinates(int x, int y);                                                           ///érvényes-e a hivatkozott cella
    void click(int x, int y);                                                                       ///kattintás egy adott cellára
    void deploy_fleet(int x, int y);                                                                ///flotta elhelyezése

    void set_current_ship_pos(int x, int y)                                                         ///jelenlegi hajó pozíciójának beállítása
    {
        _current_ship_x=x;
        _current_ship_y=y;
    }
    void set_current_ship_size(int w, int h)                                                        ///jelenlegi hajó méretének beállítása
    {
        //cout<<w<<"\t"<<h<<endl;
        _current_ship_w=w;
        _current_ship_h=h;
        //cout<<_current_ship_w<<"\t"<<_current_ship_h<<endl;
    }
    vector<string>* get_ammo()                                                                      ///lehetséges lőszerek neveinek lekérése
    {
        return &_str_ammo;
    }
    vector<string>* get_ships()                                                                     ///lehetséges hajók méretének lekérése
    {
        return &_str_ships;
    }
    void set_ammo(string str);                                                                      ///lőszer beállítása
    gamestates get_gamestate()                                                                      ///játékállás lekérése
    {
        return _state;
    }
    void set_ship(string str);                                                                      ///jelenlegihajóméret beállítása
};

#endif // GAMEMASTER_HPP_INCLUDED
