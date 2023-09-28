//
// Created by Mario O Salinas on 9/27/23.
//
#include <iostream>
using namespace std;

int main() {
    ifstream inputFile;
    ofstream outputFile;
    char command;     // operation to be executed

    SortedType list;
    ItemType item;

    cout << "Enter the name of the input file: ";
    cin >> inputFileName;
    inputFile.open(inputFileName.c_str());

    cout << "Enter the name of the output file: ";
    cin >> outputFileName;
    outputFile.open(outputFileName.c_str());

    if (!inputFile.good()) {
        cout << "I/O error. Can't find the input file! \n";
        exit(2);
    }

    cout << "S: Set up for new semester." << endl
    << "A: Add a new student." << endl
    << "P: Record programming assignment grade for all students." << endl
    << "T: Record test grade for all students." << endl
    << "F: Record Final exam grade for all students." << endl
    << "C: Change a grade for a new particular student." << endl
    << "G: Calculate final grade." << endl
    << "O: Output the grade data." << endl
    << "Q: Quit." << endl
    << "Enter your single letter-command: ";
    cin >> command;

    switch (command) {
        case S:
            break;
        case A:
            break;
        case P:
            break;
        case T:
            break;
        case F:
            break;
        case C:
            break;
        case G:
            break;
        case O:
            break;
        case Q:
            break;

    }

}
