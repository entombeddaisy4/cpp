//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
//------------------------------------------------------------------------------'
/*
	Oppgave 1
*/
//a)
//Programmet printer ut v0=25


// C++ programs start by executing the function main
int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
for (int i = 0; i < numTimes; i++) {
startValue += increment;
}
return startValue;
}
void testCallByValue() {
int v0 = 5;
int increment = 2;
int iterations = 10;
int result = incrementByValueNumTimes(v0, increment, iterations);
cout << "v0: " << v0
<< " increment: " << increment
<< " iterations: " << iterations
<< " result: " << result << endl;
}
int main() {
testCallByValue();
}

//------------------------------------------------------------------------------
