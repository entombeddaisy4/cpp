#include "std_lib_facilities.h"
#include "Animal.h"

Animal::Animal(string n, int a): name{n}, age{a}
{}

Dog::Dog(string n, int a): Animal{n, a}
{}

Cat::Cat(string n, int a): Animal{n, a}
{}

string Animal::toString() {
    string rString;
    
    rString = "Animal: " + name + ", " + to_string(age);
    return rString;
}

string Cat::toString() {
    string rString;
    
    rString = "Cat: " + name + ", " + to_string(age);
    return rString;
}

string Dog::toString() {
    string rString;
    
    rString = "Dog: " + name + ", " + to_string(age);
    return rString;
}
