#include "std_lib_facilities.h"
#include "utilities.h"

//returns a random integer between lowerLim and upperLim inclusive
int randomWithLimits(int lowerLim, int upperLim) {
    int randomNum = (rand() % (upperLim - lowerLim + 1)) + lowerLim;
    return randomNum;
}

//increments a startvalue by x n number of times and returns result
int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
for (int i = 0; i < numTimes; i++) {
startValue += increment;
}
return startValue;
}