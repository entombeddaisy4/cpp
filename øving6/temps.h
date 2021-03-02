#include "std_lib_facilities.h"

struct Temps{
    double min;
    double max;
};

istream& operator>>(istream& is, Temps& t);

vector<Temps> readTemps(string fileName);

void tempStats(string fileName);