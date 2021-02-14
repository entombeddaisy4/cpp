#include "std_lib_facilities.h"
#include "utilities.h"

//returns a random integer between lowerLim and upperLim inclusive
int randomWithLimits(int lowerLim, int upperLim) {
    int randomNum = (rand() % (upperLim - lowerLim + 1)) + lowerLim;
    return randomNum;
}

//increments a startvalue by x n number of times and returns result
int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

//increments a startvalue by x n number of times by reference
void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
}

//swaps values of two integer variables
void swapNumbers(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
//bedre å bruke referanser fordi da endrer den variablene i funksjonen, istedenfor at man må returnere begge verdiene og endre verdiene til variablene utenfor funksjonen

void printStudent(Student student) {
    cout << "Name: " << student.name << " | Study Program: " << student.studyProgram << " | Age: " << student.age << endl;
}

//returns boolean value if student is in a program or not
bool isInProgram(Student student, string program) {
    if (student.studyProgram == program) {
        return true;
    } else {
        return false;
    }
}

//returns a string with length len and characters between lowerLim and upperLim
string randomizeString(int len, char lowerLim, char upperLim) {
    int lower = lowerLim;
    int upper = upperLim;
    string randomStr;
    char randomLetter;
    for (int i = 0; i < len; i++) {
        randomLetter = randomWithLimits(lower, upper);
        randomStr += randomLetter;
    }
    return randomStr;
}

string readInputToString(int length, char lowerLim, char upperLim) {
    char lower = tolower(lowerLim);
    char upper = tolower(upperLim);
    string inputString;
    bool check;
    while (true) {
        cout << "Input a string of length " << length << " with characters between " << lowerLim << " and " << upperLim << ": ";
        cin >> inputString;
        check = true;
        for (int i = 0; i < inputString.length(); i++) {
            if (tolower(inputString[i]) < lower or tolower(inputString[i]) > upper) {
                check = false;
            }
        }
        if (inputString.length() == length and check == true) {
            return inputString;
        } else {
            cout << "Invalid input" << endl;
        }
    }
}

int countChar(string inputString, char countOp) {
    int count = 0;
    for (int i = 0; i < inputString.length(); i++) {
        if (inputString[i] == countOp) {
            count++;
        }
    }
    return count;
}