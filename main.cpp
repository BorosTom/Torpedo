#include <vector>
#include <cstdlib>
#include <ctime>
#include "graphics.hpp"
#include "Widget.hpp"
#include "Checkbox.hpp"
#include "StaticText.hpp"
#include "texteditor.hpp"
#include "Num.hpp"
#include "Window.hpp"
#include "Dropdown.hpp"
#include "Password.hpp"
#include "Push_button.hpp"


#include "My_window.hpp"
#include "CALCULATOR.hpp"
#include "KOLCSONZO.hpp"
#include "FILTER.hpp"
#include "GameMaster.hpp"
#include "TORPEDO.hpp"

#include <iostream>

using namespace std;
using namespace genv;

static const double XX=1000;
static const double YY=1000;

enum asd{a,s,d};

int main()
{


    srand(time(0));
    //My_window w(XX,YY);
    //w.event_loop();

    //CALCULATOR c(XX,YY);
    //c.event_loop();

    /*vector<string> v1={"1","2","3","4"};
    vector<string> v2={"qwe","asd","yxc","rtz"};

    KOLCSONZO k(XX,YY,v1,v2);
    k.event_loop();*/

    //CALCULATOR c(XX,YY);
    //c.event_loop();

    //FILTER f(XX,YY);
    //f.event_loop();

    /*enum asd{a,s,d};

    vector<vector<asd> > v;

    for(int i=0;i<10;i++){
        v.push_back({});
        for(int j=0;j<10;j++){
            v[i].push_back(d);
        }
    }

    cout<<v[1][1]<<endl;
    cout<<v.size();*/

    TORPEDO t(XX,YY,10,10);
    t.event_loop();

    return 0;
}
