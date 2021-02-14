//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"
#include "masterMind.h"
//------------------------------------------------------------------------------'
/*
	Oppgave 1
*/
//a)
//Programmet printer ut v0=25
int main() {
	srand(static_cast<unsigned int>(time(nullptr)));
	int menuFunc = -1;
	while (true) {
		cout << "0) Exit\n";
		cout << "1) Play Mastermind\n";
		cout << "2) testCallByValue\n";
		cout << "3) Test struct Student\n";

		cout << "Choose function: \n";
		cin >> menuFunc;

		switch (menuFunc) {
			case 0:
				return 0;
			case 1:
				playMastermind();
				break;
			case 2:
				testCallByValue();
				testCallByReference();
				testSwapNumbers();
				break;
			case 3:
				{
				Student jokke = {"Joakim", "MTKJ", 19};
				printStudent(jokke);
				cout << isInProgram(jokke, "MTKJ") << endl << isInProgram(jokke, "MTNANO") << endl;
				break;
				}
			default:
				cout << "Invalid input\n";
				break;
		}
	}
}

//------------------------------------------------------------------------------
