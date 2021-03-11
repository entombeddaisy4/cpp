#include "vehicle.h"

// Implement all the necessary functions as described in the task here.

Vehicle::Vehicle(string n, Color c, double v): name{n}, colour{c}, speed{v}
{}

bool Vehicle::allowedSpeed() {
    if (speed < 1000) {
        return true;
    } else {
        return false;
    }
}

Car::Car(string n, Color c, double v, int nw): Vehicle{n, c, v}, numberOfWheels{nw}
{}

void Car::changeColor(Color newcolor) {
    colour = newcolor;
}

bool Car::allowedSpeed() {
    if (speed > 100) {
        return false;
    } else {
        return true;
    }
}

