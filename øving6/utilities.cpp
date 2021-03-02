#include "std_lib_facilities.h"
#include "utilities.h"

void wordsToFile() {
    string oname = "oppgave1a.txt";
    ofstream ofs{ oname };
    if (!ofs) {
        error("Cannot open output file ", oname);
        return;
    }
    string istring;
    cout << "Input words(quit to stop):" << endl;
    while (true) {
        cin >> istring;
        if (istring == "quit") {
            return;
        }
        ofs << istring << "\n";
    }
}

void copyWithLinenumbers() {
    cout << "Which file do you want to read from?: ";
    string iname;
    cin >> iname;
    ifstream ist { iname };
    string oname = "linenumbers_" + iname;
    ofstream ofs { oname };
    int i = 1;
    string line;
    while (getline(ist, line)) {
        ofs << i << " " << line << "\n";
        i++;
    }
}

void characterStats() {
    cout << "Which file do you want to read from?: ";
    string iname;
    cin >> iname;
    ifstream ist { iname };
    string oname = "linenumbers_" + iname;
    ofstream ofs { oname };
    string line;
    vector<int> charStats(26,0);
    
    int number;
    char character;
    while (getline(ist, line)) {
        for (int i = 0; i < line.length(); i++) {
            character = line[i];
            number = static_cast<int>(tolower(character))-97;
            if (number >= 0 and number <= 25) {
                charStats[number]++;
            }
        }
    }
    for (int i = 0; i < charStats.size(); i++) {
        character = i + 97;
        cout << character << ": " << charStats[i] << " ";
        if ((i+1) % 3 == 0) {
            cout << "\n";
        }
    }
    cout << "\n\n";
}