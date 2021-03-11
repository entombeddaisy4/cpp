#pragma once

// Include Graph_lib library files that holds declarations needed for Window,
// and Shape derivatives.
#include "Graph.h"
#include "GUI.h"



using namespace Graph_lib;

// An abstract class. Concrete classes derived from this base class
// has to implement the member function attach_to().
class Emoji
{
public:
	// Disable copying. Disable slicing, etc.
	Emoji(const Emoji&) = delete;
	Emoji& operator=(const Emoji&) = delete;

	// Deleting the copy constructor also deletes the default constructor.
	// Emoji needs a default constructor.
	Emoji() {}
	// Emoji() = default; // is an alternative way of achieving the same.

	// The pure virtual function that has to be overriden for a deriving class
	// to be instantiable. Every class deriving from Emoji is supposed to
	// attach all its Shapes to a window. This makes the class abstract.
	virtual void attach_to(Graph_lib::Window&) = 0;

	// Relevant because Vector_ref can own Emojis and automatically cleans up.
	// Subject will be visited later in the course.
	virtual ~Emoji() {}
};

class Face : public Emoji {
protected:
	Circle faceCircle;
public:
	Face(Point C, int r);
	virtual void attach_to(Graph_lib::Window& win) = 0;
};


class EmptyFace : public Face {
protected:
	Point re;
    Point le;
	Circle leftEye;
	Circle rightEye;
public:
	EmptyFace(Point C, int r);
	virtual void attach_to(Graph_lib::Window& win);
};

class KillMeNow : public EmptyFace {
protected:
	Point m1;
	Point m2;
	Rectangle mouth;
public:
	KillMeNow(Point C, int r);
	void attach_to(Graph_lib::Window& win);
};

class Smiley : public EmptyFace {
protected:
	Point m;
	Arc mouth;
public:
	Smiley(Point C, int r);
	void attach_to(Graph_lib::Window& win);
};
