#include "Window.hpp"



void Window::event_loop()
{
    event ev;
    while(gin >> ev && ev.keycode != key_escape)
    {   custom(ev);
        if (ev.type == ev_mouse && ev.button==btn_left)
        {
            focus=-1;
            for (size_t i=0; i<_vec.size(); i++)
            {
                if (_vec[i]->selected(ev.pos_x, ev.pos_y))
                {
                    if(_vec[i]->get_focusable())
                    {
                        focus = i;
                    }
                    else
                    {
                        _vec[i]->set_selected(false);
                    }
                }
                else
                {
                    _vec[i]->set_selected(false);
                }
            }
            if(focus!=-1)
            {
                _vec[focus]->set_selected(true);
            }
        }

        if(ev.type==ev_key && ev.keycode==key_tab)
        {
            for (int i=0; i<int(_vec.size()); i++)
            {
                _vec[i]->set_selected(false);
            }
            bool ready=false;
            while(!ready)
            {
                focus++;
                if(focus>=int(_vec.size()))
                {
                    focus=-1;
                    ready=true;
                }
                else if(!_vec[focus]->get_focusable()) {}
                else
                {
                    ready=true;
                }
            }

            if(focus!=-1)
            {
                _vec[focus]->set_selected(true);
            }
        }

        if (focus!=-1)
        {
            _vec[focus]->handle(ev);
        }
        cls(_xx,_yy,Color(BLACK));
        for (size_t i=0; i<_vec.size(); i++)
        {
            _vec[i]->draw();
        }
        gout << refresh;
    }
}
