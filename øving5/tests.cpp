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

void testCallByReference() {
	int v0 = 5;
	int v = v0;
	int increment = 2;
	int iterations = 10;
	incrementByValueNumTimesRef(v, increment, iterations);
	cout << "v0: " << v0
	<< " increment: " << increment
	<< " iterations: " << iterations
	<< " result: " << v << endl;
}

void testSwapNumbers() {
	int a = 5;
	int b = 27;
	cout << "Before \na = " << a << " b = " << b << endl;
	swapNumbers(a,b);
	cout << "After\na= " << a << " b = " << b << endl;
}

void testString() {
	string grades = randomizeString(8, 'A', 'F');
	vector<int> gradeCount{countChar(grades, 'A'),countChar(grades, 'B'),countChar(grades, 'C'),countChar(grades, 'D'),countChar(grades, 'E'),countChar(grades, 'F')};
	double sum = 0;
	sum += 5*gradeCount[0];
	sum += 4*gradeCount[1];
	sum += 3*gradeCount[2];
	sum += 2*gradeCount[3];
	sum += 1*gradeCount[4];
	double average = sum / grades.length();
	cout << "Average grade is " << average << endl;
}