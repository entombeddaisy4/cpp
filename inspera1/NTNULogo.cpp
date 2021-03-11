#include "NTNULogo.h"

#include "Simple_window.h"
#include "std_lib_facilities.h"

using namespace Graph_lib;

constexpr Point origo{Point{0, 0}};
constexpr int radius{85};
constexpr int pad{100};
const string title{"NTNU Logo"};

void drawNTNULogo(){

    //Kalle konstrutører som trengs for å tegne logo:
    Simple_window win{origo, 5* pad, 5* pad, title}; 
    
    Point mid{2*pad, 2*pad};
    Circle midCircle{mid, radius};
    
    Point midtopleft{pad, pad};
    Point midbottomright{3*pad, 3*pad};
    Point midtopright{3*pad, pad};
    Point midbottomleft{pad, 3*pad};
    Point vertical1{pad,0};
    Point vertical2{3*pad, 4*pad};
    Rectangle vertical{vertical1, vertical2};
    vertical.set_fill_color(Color::blue);
    win.attach(vertical);
    Point horizontal1{0,pad};
    Point horizontal2{4*pad, 3*pad};
    Rectangle horizontal{horizontal1, horizontal2};
    horizontal.set_fill_color(Color::blue);
    win.attach(horizontal);

    Circle topleft{midtopleft, pad};
    topleft.set_fill_color(Color::blue);
    topleft.set_color(Color::blue);
    win.attach(topleft);

    Circle topright{midtopright, pad};
    topright.set_fill_color(Color::blue);
    topright.set_color(Color::blue);
    win.attach(topright);

    Circle bottomleft{midbottomleft, pad};
    bottomleft.set_fill_color(Color::blue);
    bottomleft.set_color(Color::blue);
    win.attach(bottomleft);

    Circle bottomright{midbottomright, pad};
    bottomright.set_fill_color(Color::blue);
    bottomright.set_color(Color::blue);
    win.attach(bottomright);
    


    Rectangle whitemid{midtopleft, midbottomright};
    whitemid.set_fill_color(Color::white);
    win.attach(whitemid);
    

    midCircle.set_fill_color(Color::blue);
    win.attach(midCircle);

    
    //Sette fyll-farge:

    //Fjerne kanter: Shape.set_color(Color::invisible): 

    //Tegne figurer:

    win.wait_for_button();
}
