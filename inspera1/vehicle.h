#pragma once
#include "std_lib_facilities.h"

// Task a)
// Create an color enum here
enum class Color {blue, yellow, red, green};

// Task b) 
// Complete the Vehicle class as described in the task
class Vehicle {
protected:
    string name;
    Color colour;
    double speed;
public:
    Vehicle(string n, Color c, double v);
    virtual bool allowedSpeed();
};

class Car : public Vehicle {
private:
    int numberOfWheels;
public:
    Car(string n, Color c, double v, int nw);
    void changeColor(Color newcolor);
    bool allowedSpeed();
};


// Task c)
// Create the Car class underneath as described in the task
