#include "std_lib_facilities.h"
#include "courses.h"

CourseCatalog::CourseCatalog(){

}

void CourseCatalog::addCourse(string code, string name) {
    courses[code] = name;
}

void CourseCatalog::removeCourse(string code) {
    courses.erase(code);
}

string CourseCatalog::getCourse(string code) {
    return courses[code];
}

ostream& operator<<(ostream& os,const CourseCatalog& c) {
    for (const auto& m:c.courses) {
        os << m.first << "\t" << m.second << "\n";
    }
    return os;
} 

void CourseCatalog::saveData() {
    ofstream ofs{ "CourseData.txt" };
    string istring;
    for (const auto& m:courses) {
        ofs << m.first << ";" << m.second << "\n";
    }
}

void CourseCatalog::loadData() {
    ifstream ifs{"CourseData.txt"};
    string code;
    string name;
    string line;
    int data;
    while (getline(ifs, line)) {
        data =  line.find(';');
        courses[line.substr(0,(data-1))] = line.substr(data+1);
    }
}