#include "std_lib_facilities.h"
#include "temps.h"

istream& operator>>(istream& is, Temps& t) {
    is >> t.max;
    is >> t.min;

    return is;    
}


vector<Temps> readTemps(string fileName) {
    Temps tempTemps;
    ifstream ifs{fileName};
    vector<Temps> tempVector;
    while (ifs >> tempTemps) {
        tempVector.push_back(tempTemps);
    }
    return tempVector;
}

void tempStats(string fileName) {
    vector<Temps> tempVec = readTemps(fileName);
	int maxIndex;
    double maxValue;
    int minIndex;
    double minValue;
    for (int i = 0; i < tempVec.size(); i++) {
		if (tempVec[i].max > maxValue) {
            maxValue = tempVec[i].max;
            maxIndex = i;
        }
        if (tempVec[i].min < minValue) {
            minValue = tempVec[i].min;
            minIndex = i;
        }
	}	
    cout << "Absolute maximum temp was " << maxValue << " at index " << maxIndex << endl;
    cout << "Absolute minimum temp was " << minValue << " at index " << minIndex << endl;
}