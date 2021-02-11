#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"

void testDeviation(double compareOperand, double toOperand, double maxError, string name) {
	if (abs(compareOperand - toOperand) <= maxError) {
		cout << "Test \"" << name << "\" \033[;32mpassed.\033[0m\n";	
	} else {
		cout << "\033[1;31mTest \"" << name << "\" failed.\033[0m\n";
		cout << "\t Expected result : " << toOperand << "\n";
		cout << "\t Actual result   : " << compareOperand << "\n";
	}
}

void testCallByValue(int compareOperand, int toOperand, string name) {
    if (compareOperand == toOperand) {
		cout << "Test \"" << name << "\" \033[;32mpassed.\033[0m\n";	
	} else {
		cout << "\033[1;31mTest \"" << name << "\" failed.\033[0m\n";
		cout << "\t Expected result : " << toOperand << "\n";
		cout << "\t Actual result   : " << compareOperand << "\n";
	}
}