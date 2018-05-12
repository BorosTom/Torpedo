#include "GameMaster.hpp"
#include "Misc.hpp"


GameMaster::GameMaster(int w, int h, bool single)
        :_map_w(w),_map_h(h),_state(deploy1),_singleplayer(single),_current_ship_x(0), _current_ship_y(0),_current_ship_w(0),
         _current_ship_h(0),_wait_for_direction(false)
{
    for(int i=0;i<_map_w;i++){
        _player1_own.push_back({});
        _player1_enemy.push_back({});
        _player2_own.push_back({});
        _player2_enemy.push_back({});
        for(int j=0;j<_map_h;j++){
            _player1_own[i].push_back({nullptr,false});
            _player1_enemy[i].push_back({nullptr,false});
            _player2_own[i].push_back({nullptr,false});
            _player2_enemy[i].push_back({nullptr,false});
        }
    }
    for(int i=0;i<4;i++){
        _pair_ships.push_back({1,i+1});
        _pair_ships.push_back({1,i+1});
    }

    for(size_t i=0;i<_pair_ships.size();i++){
        _str_ships.push_back(tostring(_pair_ships[i].first)+tostring(_pair_ships[i].second));
    }
}

bool GameMaster::valid_coordinates(int x, int y)
{
    return x>=0 && y>=0 && x<_map_w && y<_map_h;
}

void GameMaster::click(int x, int y)
{
    switch(_state)
    {
    case deploy1:
        deploy_fleet(x,y,&_player1_own);
        break;
    case deploy2:
        deploy_fleet(x,y,&_player2_own);
        break;
    case pl1:

        break;
    case pl2:

        break;
    default:

        break;
    }
}

void GameMaster::deploy_fleet(int x, int y, vector<vector<pair<Ship*,bool> > >* table)
{
    if(!_wait_for_direction){

    }
    else{

    }
}
