#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "date.h"
using namespace std;


struct Income {
    Date date;
    string source;
    int summ;
};

int main() {
    setlocale(LC_ALL, "Ru");
    vector<Income> objects;
    ifstream file("resources.txt");

    if (!file.is_open()) {
        cerr << "cant open file" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        Income obj;
        istringstream iss(line);

        char dot;
        iss >> obj.date.year >> dot >> obj.date.month >> dot >> obj.date.day;
        iss >> obj.source >> obj.summ;

        objects.push_back(obj);
    }

    file.close();

    for (const Income& obj : objects) {
        cout << "Date: ";
        obj.date.print();
       
        cout << "Source: " << obj.source << endl;
        cout << "Sum: " << obj.summ << " rubles" << endl;
        cout << endl;
    }

    return 0;
}




