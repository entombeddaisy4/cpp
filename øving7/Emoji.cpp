#include "Emoji.h"
#include "Graph.h"

Face::Face(Point C, int r): faceCircle{C, r}
{
    faceCircle.set_fill_color(Color::blue);
}

void Face::attach_to(Graph_lib::Window& win) {
    win.attach(faceCircle);
}


EmptyFace::EmptyFace(Point C, int r) : Face{C, r},
re{C.x+(r/3), C.y-(r/3)},
le{C.x-(r/3), C.y-(r/3)},
leftEye{le, r/4},
rightEye{re, r/4}
{
    leftEye.set_fill_color(Color::red);
    rightEye.set_fill_color(Color::green);
}

void EmptyFace::attach_to(Graph_lib::Window& win) {
    Face::attach_to(win);
    win.attach(leftEye);
    win.attach(rightEye);
}

KillMeNow::KillMeNow(Point C, int r) : EmptyFace{C, r},
m1{C.x-r/4,C.y+r/3},
m2{C.x+r/4,C.y+r/2},
mouth{m1, m2}
{
    mouth.set_fill_color(Color::yellow);
}

void KillMeNow::attach_to(Graph_lib::Window& win) {
    EmptyFace::attach_to(win);
    win.attach(mouth);
}

Smiley::Smiley(Point C, int r) : EmptyFace{C, r},
m{C.x, C.y+r/5},
mouth{m, static_cast<int>(r/1.5), static_cast<int>(r/1.5), 270-30, 270+30}
{
    mouth.set_fill_color(Color::magenta);
    mouth.set_color(Color::magenta);
}

void Smiley::attach_to(Graph_lib::Window& win) {
    EmptyFace::attach_to(win);
    win.attach(mouth);
}