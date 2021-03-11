#include "survey2021.h"

// Implement all the necessary functions as described in the task.

map<string, int> mapSurvey() {
    map<string, int> surveyResults;
    string line;
    string word;
    ifstream ist{"survey_2021.txt"};
    if (!ist) {
        cout << "Can't open file" << endl;
        return surveyResults;
    }
    while (getline(ist, line)) {
        istringstream iss(line);
        while(getline(iss, word, ' ')) {
            surveyResults[word] += 1;
        }
    }
    return surveyResults;
    
}

vector<string> sortVector(map<string,int> unsortedMap) {
    vector<string> result;
    vector<pair<string,int>> sortingVector;
    for (const auto& m:unsortedMap) {
		sortingVector.push_back(m);
	}
    int sorted = 1;
    pair<string, int> temp;

    while (true) {
        sorted = 1;
        for (int i = 0; i < sortingVector.size()-1; i++) {
            if (sortingVector[i].second < sortingVector[i+1].second) {
                temp = sortingVector[i];
                sortingVector[i] = sortingVector[i+1];
                sortingVector[i+1] = temp;
                sorted = 0;
            }
        }
        if (sorted == 1) {
            break;
        }
    }
    for (int i = 0; i < sortingVector.size(); i++) {
        result.push_back(sortingVector[i].first);
    }
    return result;
}

void surveyResults(map<string,int> surveyMap, vector<string> sortedVector) {
    ofstream ofs{"surveyresult.txt"};
    ofs << "Survey results 2021:" << "\n" << "----------------" << "\n"; 
    for (const auto& v:sortedVector) {
        ofs << v << ", " << surveyMap[v] << "\n";
    }
}