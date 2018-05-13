#ifndef TORPEDO_INTERFACE_HPP_INCLUDED
#define TORPEDO_INTERFACE_HPP_INCLUDED

#include "Widget.hpp"
#include <functional>
#include <vector>

enum cell_state{emptycell,miss,ok,damaged,destroyed,sinked};

class Torpedo_interface: public Widget
{
private:
    function<void()> _f;                                            ///kattintáskor meghívódó függvény
    int _cell_piece_w, _cell_piece_h;                               ///a játéktér mérete cellaszámban
    int _table_x, _table_y, _table_w, _table_h;                     ///a játéktér pozíciója és mérete pixelben
    vector<pair<double,double> > _interval_w, _interval_h;          ///az egyes cellákhoz rendelt pixel intervallumok
    vector<vector<cell_state> > _table_own, _table_enemy;           ///a cellák állapota
    double _h_offset;                                               ///az alsó tábla függõleges eltolása
    int _text_size=20;                                              ///a feliratoknak fenntartott magasság (és szélesség)
    int _click_x, _click_y;                                         ///a jelenleg kattintott cella

    Color   _grid_color, _gridbg_color, _text_color, _live_color,   ///a kirajzolás színei
            _damaged_color, _destroyed_color, _sinked_color;
public:

    Torpedo_interface(int x, int y, int w, int h, function<void()> f, int size_x, int size_y, bool autoscale=true);

    virtual void draw() const;                                      ///kirajzolás
    virtual void handle(genv::event ev);                            ///esemény kezelés
    virtual string get_value() const                                ///widget értékének lekérdezése
    {
        return "";
    }
    virtual void set_grid_color(col c){                             ///keret szín beállítása
        _grid_color.set_color(c);
    }
    virtual void set_gridbg_color(col c){                           ///tábla háttér szín beállítása
        _gridbg_color.set_color(c);
    }
    virtual void set_text_color(col c){                             ///szöveg szín beállítása
        _text_color.set_color(c);
    }
    virtual void set_live_color(col c){                             ///sértetlen elemek szín beállítása
        _live_color.set_color(c);
    }
    virtual void set_damaged_color(col c){                          ///sérült elemek szín beállítása
        _damaged_color.set_color(c);
    }
    virtual void set_destroyed_color(col c){                        ///elpusztult elemek szín beállítása
        _destroyed_color.set_color(c);
    }
    virtual void set_sinked_color(col c){                           ///elsüllyedt elemek szín beállítása
        _sinked_color.set_color(c);
    }

    void draw_miss(int i, int j, bool offset) const;                ///nem talált cella kirajzolása
    void draw_ok(int i, int j, bool offset) const;                  ///épp cella kirajzolása
    void draw_damaged(int i, int j, bool offset) const;             ///sérült cella kirajzolása
    void draw_destroyed(int i, int j, bool offset) const;           ///elpusztult cella kirajzolása
    void draw_sinked(int i, int j, bool offset) const;              ///elsüllyedt cella kirajzolása

    void set_cell_state(bool enemy, int x, int y, cell_state cs);   ///egy cella állapotának változtatása

    pair<int,int> get_click_coord(){
        return pair<int,int>{_click_x,_click_y};
    }
};

#endif // TORPEDO_INTERFACE_HPP_INCLUDED
