#ifndef TORPEDO_INTERFACE_HPP_INCLUDED
#define TORPEDO_INTERFACE_HPP_INCLUDED

#include "Widget.hpp"
#include <functional>
#include <vector>

class Torpedo_interface: public Widget
{
private:
    function<void()> _f;
    int _cell_piece_w, _cell_piece_h, _table_x, _table_y, _table_w, _table_h;
    vector<pair<double,double> > _interval_w, _interval_h;
    double _h_offset;
    int _text_size=20;

    Color _grid_color, _gridbg_color, _text_color, _live_color, _damaged_color, _destroyed_color, _sinked_color;
public:

    Torpedo_interface(int x, int y, int w, int h, function<void()> f, int size_x, int size_y, bool autoscale=true);

    virtual void draw() const;
    virtual void handle(genv::event ev);
    virtual string get_value() const
    {
        return "";
    }
    virtual void set_grid_color(col c){
        _grid_color.set_color(c);
    }
    virtual void set_gridbg_color(col c){
        _gridbg_color.set_color(c);
    }
    virtual void set_text_color(col c){
        _text_color.set_color(c);
    }
    virtual void set_live_color(col c){
        _live_color.set_color(c);
    }
    virtual void set_damaged_color(col c){
        _damaged_color.set_color(c);
    }
    virtual void set_destroyed_color(col c){
        _destroyed_color.set_color(c);
    }
    virtual void set_sinked_color(col c){
        _sinked_color.set_color(c);
    }


};

#endif // TORPEDO_INTERFACE_HPP_INCLUDED
