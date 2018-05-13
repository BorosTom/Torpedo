#ifndef TORPEDO_INTERFACE_HPP_INCLUDED
#define TORPEDO_INTERFACE_HPP_INCLUDED

#include "Widget.hpp"
#include <functional>
#include <vector>

enum cell_state{emptycell,miss,ok,damaged,destroyed,sinked};

class Torpedo_interface: public Widget
{
private:
    function<void()> _f;                                            ///kattint�skor megh�v�d� f�ggv�ny
    int _cell_piece_w, _cell_piece_h;                               ///a j�t�kt�r m�rete cellasz�mban
    int _table_x, _table_y, _table_w, _table_h;                     ///a j�t�kt�r poz�ci�ja �s m�rete pixelben
    vector<pair<double,double> > _interval_w, _interval_h;          ///az egyes cell�khoz rendelt pixel intervallumok
    vector<vector<cell_state> > _table_own, _table_enemy;           ///a cell�k �llapota
    double _h_offset;                                               ///az als� t�bla f�gg�leges eltol�sa
    int _text_size=20;                                              ///a feliratoknak fenntartott magass�g (�s sz�less�g)
    int _click_x, _click_y;                                         ///a jelenleg kattintott cella

    Color   _grid_color, _gridbg_color, _text_color, _live_color,   ///a kirajzol�s sz�nei
            _damaged_color, _destroyed_color, _sinked_color;
public:

    Torpedo_interface(int x, int y, int w, int h, function<void()> f, int size_x, int size_y, bool autoscale=true);

    virtual void draw() const;                                      ///kirajzol�s
    virtual void handle(genv::event ev);                            ///esem�ny kezel�s
    virtual string get_value() const                                ///widget �rt�k�nek lek�rdez�se
    {
        return "";
    }
    virtual void set_grid_color(col c){                             ///keret sz�n be�ll�t�sa
        _grid_color.set_color(c);
    }
    virtual void set_gridbg_color(col c){                           ///t�bla h�tt�r sz�n be�ll�t�sa
        _gridbg_color.set_color(c);
    }
    virtual void set_text_color(col c){                             ///sz�veg sz�n be�ll�t�sa
        _text_color.set_color(c);
    }
    virtual void set_live_color(col c){                             ///s�rtetlen elemek sz�n be�ll�t�sa
        _live_color.set_color(c);
    }
    virtual void set_damaged_color(col c){                          ///s�r�lt elemek sz�n be�ll�t�sa
        _damaged_color.set_color(c);
    }
    virtual void set_destroyed_color(col c){                        ///elpusztult elemek sz�n be�ll�t�sa
        _destroyed_color.set_color(c);
    }
    virtual void set_sinked_color(col c){                           ///els�llyedt elemek sz�n be�ll�t�sa
        _sinked_color.set_color(c);
    }

    void draw_miss(int i, int j, bool offset) const;                ///nem tal�lt cella kirajzol�sa
    void draw_ok(int i, int j, bool offset) const;                  ///�pp cella kirajzol�sa
    void draw_damaged(int i, int j, bool offset) const;             ///s�r�lt cella kirajzol�sa
    void draw_destroyed(int i, int j, bool offset) const;           ///elpusztult cella kirajzol�sa
    void draw_sinked(int i, int j, bool offset) const;              ///els�llyedt cella kirajzol�sa

    void set_cell_state(bool enemy, int x, int y, cell_state cs);   ///egy cella �llapot�nak v�ltoztat�sa

    pair<int,int> get_click_coord(){
        return pair<int,int>{_click_x,_click_y};
    }
};

#endif // TORPEDO_INTERFACE_HPP_INCLUDED
