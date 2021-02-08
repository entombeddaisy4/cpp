#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"

void testDeviation(double compareOperand, double toOperand, double maxError, string name);

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	int menuFunc = -1;
	while (true) {
		cout << "0) Exit\n";
		cout << "1) Play Target Practice\n";
		cout << "2) Run selftest\n";
		cout << "3) Test RNG\n";

		cout << "Choose function: \n";
		cin >> menuFunc;

		switch (menuFunc) {
			case 0:
				return 0;
			case 1:
				playTargetPractice();
				break;
			case 2:
				cout << "Running tests\n";
				testDeviation(acclY(), -9.81, 0.0001, "acclY");
				testDeviation(velY(25, 0), 25.0, 0.0001, "velY - T = 0.0");
				testDeviation(velY(25, 2.5), 0.475, 0.0001, "velY - T = 2.5");
				testDeviation(velY(25, 5), -24.05, 0.0001, "velY - T = 5.0");
				testDeviation(posX(0, 50, 0), 0, 0.0001, "posX - T = 0.0");
				testDeviation(posX(0, 50, 2.5), 125, 0.0001, "posX - T = 2.5");
				testDeviation(posX(0, 50, 5), 250, 0.0001, "posX - T = 5.0");
				testDeviation(posY(0, 25, 0), 0, 0.0001, "posY - T = 0.0");
				testDeviation(posY(0, 25, 2.5), 31.84, 0.01, "posY - T = 2.5");
				testDeviation(posY(0, 25, 5), 2.375, 0.0001, "posY - T = 5.0");
				testDeviation(degToRad(90), M_PI_2, 0.0001, "degToRad (90°)");
				testDeviation(getVelocityX(M_PI_4, 1), 0.70710678118, 0.0001, "getVelocityX (pi/4)");
				testDeviation(getVelocityY(M_PI_4, 1), 0.70710678118, 0.0001, "getVelocityY (pi/4)");
				testDeviation(getDistanceTraveled(getVelocityX(degToRad(45), 40), getVelocityY(degToRad(45), 40)), 163.27, 0.2, "getDistanceTraveled (45 degrees, 40 velocity)");
				break;
			case 3:
				for (int i = 1; i <= 50; i++) {
					cout << randomWithLimits(0, 9) << "\t";
					if (i % 5 == 0) {
						cout << "\n\n";
					}
				}
				break;
			default:
				cout << "Invalid input\n";
				break;
		}
	}
}

//oppgave 3
//Compares two floats and prints either "Test x passed" or "Test x failed" and expected result vs actual result
void testDeviation(double compareOperand, double toOperand, double maxError, string name) {
	if (abs(compareOperand - toOperand) <= maxError) {
		cout << "Test \"" << name << "\" \033[;32mpassed.\033[0m\n";	
	} else {
		cout << "\033[1;31mTest \"" << name << "\" failed.\033[0m\n";
		cout << "\t Expected result : " << toOperand << "\n";
		cout << "\t Actual result   : " << compareOperand << "\n";
	}
}