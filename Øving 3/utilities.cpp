#include "utilities.h"
#include "std_lib_facilities.h"

//returns a random integer between lowerLim and upperLim inclusive
int randomWithLimits(int lowerLim, int upperLim) {
    int randomNum = (rand() % (upperLim - lowerLim + 1)) + lowerLim;
    return randomNum;
}