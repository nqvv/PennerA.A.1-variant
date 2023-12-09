#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "date.h"
#include "income.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");
    vector<Income> objects;
    ifstream file("resources.txt");

    if (!file.is_open()) {
        cerr << "cant open file" << endl;
        return 1;
    }
   
    while (!file.eof())
        objects.push_back(Income::read(file));

    for (const Income& obj : objects)
        obj.print();
 
    return 0;
}