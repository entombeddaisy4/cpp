#include "std_lib_facilities.h"
#include "survey2021.h"
#include "vehicle.h"
#include "NTNULogo.h"



int main()
{
	cout << "Hello TDT4102 insperaøving 1!\n";

	map<string, int>mapp = mapSurvey();
	surveyResults(mapp, sortVector(mapp));
	drawNTNULogo();
	keep_window_open();
}
