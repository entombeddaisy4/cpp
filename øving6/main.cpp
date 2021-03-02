#include "std_lib_facilities.h"
#include "utilities.h"
#include "courses.h"
#include "temps.h"

int main()
{
	int menuFunc;
	CourseCatalog c;
	while (true) {
		cout << "0) Exit\n";
		cout << "1) Oppgave 1a\n";
		cout << "2) Oppgave 1b\n";
		cout << "3) Oppgave 2a\n";
		cout << "4) Oppgave 3c/d\n";
		cout << "5) Oppgave 3e\n";
		cout << "6) Oppgave 4b/c/d\n";

		cout << "Choose function: \n";
		cin >> menuFunc;

		switch (menuFunc) {
			case 0:
				return 0;
			case 1:{
				wordsToFile();
				break;
			}
			case 2: 
				copyWithLinenumbers();
				break;
			case 3:
				characterStats();
				break;
			case 4: {
				c.addCourse("TDT4110","Informasjonsteknologi grunnkurs");
				c.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
				c.addCourse("TMA4100", "Matematikk 1");
				cout << c;
				c.addCourse("TDT4102", "C++");
				cout << c;
				c.saveData();
				break;
			}
			case 5: 
				c.loadData();
				cout << c;
				break;
			case 6: {
				vector<Temps> vec = readTemps("temperatures.txt");
				for (int i = 0; i < vec.size(); i++) {
					cout << "Max: " << vec[i].max << " | min: " << vec[i].min << endl;
				}
				tempStats("temperatures.txt");
				break;
			}
			default:
				cout << "Invalid input\n";
				break;
		}
	}
}
