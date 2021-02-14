#include "std_lib_facilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes);
void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);
int randomWithLimits(int lowerLim, int upperLim);
void swapNumbers(int& a, int& b);

struct Student {
    string name;
    string studyProgram;
    int age;
};

void printStudent(Student student);

bool isInProgram(Student student, string program);

string randomizeString(int len, char lowerLim, char upperLim);

string readInputToString(int length, char lowerLim, char upperLim);

int countChar(string inputString, char countOp);