//
// Created by Mario O Salinas on 9/27/23.
//
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string inputFileName, outputFileName;
    ifstream inputFile;
    ofstream outputFile;
    char command = 'I';     // operation to be executed. initialized to 'I' as a dummy place-holder

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

    while (command != 'Q') {
        // define variables that will be used under the scope of this while loop
        string studentName;

        cout << "S: Set up for new semester." << endl
             << "A: Add a new student." << endl
             << "P: Record programming assignment grade for all students." << endl
             << "T: Record test grade for all students." << endl
             << "F: Record Final exam grade for all students." << endl
             << "C: Change a grade for a new particular student." << endl
             << "G: Calculate final grade." << endl
             << "O: Output the grade data." << endl
             << "Q: Quit." << endl
             << "Enter your single letter-command: " << endl;
        cin >> command;

        if (command != 'Q') {
            switch (command) {
                case 'S':
                case 's':
                    cout << "You have selcted to set up for a new semester." << endl;
                    // define variables
                    int numAssignments, numTests, numFinalExams;
                    float assignmentWeight, testWeight, examWeight;

                    // prompt the user for int values
                    cout << "Enter the number of semester assignments: ";
                    cin >> numAssignments;
                    while (numAssignments < 0 || numAssignments > 6) {
                        cout << "You must enter a number between 0 and 6. Enter the number of semester assignments: ";
                        cin >> numAssignments;
                    }
                    cout << "Enter the number of tests: ";
                    cin >> numTests;
                    while (numTests < 0 || numTests > 4) {
                        cout << "You must enter a number between 0 and 4. Enter the number of semester assignments: ";
                        cin >> numTests;
                    }
                    cout << "Enter the number of exams: ";
                    cin >> numFinalExams;
                    while (numFinalExams < 0 || numFinalExams > 1) {
                        cout << "You must enter either 0 or 1. Enter the number of semester assignments: ";
                        cin >> numFinalExams;
                    }
                    // prompt user for float values
                    cout << "Enter the relative weight of assignments as a decimal: ";
                    cin >> assignmentWeight;
                    cout << "Enter the relative weight of tests as a decimal: ";
                    cin >> testWeight;
                    cout << "Enter the relative weight of the final exam as a decimal: ";
                    cin >> examWeight;
                    while (assignmentWeight + testWeight + examWeight != 1.0) {
                        cout
                                << "The sum total of your relative weights must equal 1.0. The sum of your relative weights"
                                   "does not equal zero. Try again.";
                        cout << "Enter the relative weight of assignments as a decimal: ";
                        cin >> assignmentWeight;
                        cout << "Enter the relative weight of tests as a decimal: ";
                        cin >> testWeight;
                        cout << "Enter the relative weight of the final exam as a decimal: ";
                        cin >> examWeight;
                    }
                    break;
                case 'A':
                case 'a':
                    int studentIDNumber;
                    cout << endl << "*** You have selected to add a new student. ***" << endl;
                    cin.ignore();
                    cout << "Enter the student's first and last name seperated by a space: ";
                    getline(cin, studentName);
                    cout << "Enter the student's ID number: ";
                    cin >> studentIDNumber;
                    break;
                case 'P':
                case 'p':
                    cout << endl << "*** You have selected to record assignment grades for all students. ***" << endl;
                    break;
                case 'T':
                case 't': {
                    // i use brackets here so that the program will allow me to initialize my integer variables
                    // inside of this case
                    int testNumber;
                    int repeatSwitchCase = 1;
                    cout << endl << "*** You have selected to record test grades for all students. ***" << endl;
                    while (repeatSwitchCase != 0) {
                        cout << "Enter the test number for which you will enter a grade: ";
                        cin >> testNumber;
                        // verify that the user entered a valid test number. a valid test number is
                        // one that is less than numTest, and that has not been previously recorded
                        while (testNumber > numTests || testNumber < 0) {
                            cout << "Invalid test number. You cannot input a number less than zero or a number " << endl
                                 << "greater than the number of tests you have assigned to your students. Try again."
                                 << endl;
                            cout << "Enter the testNumber for which you will enter a grade: ";
                            cin >> testNumber;
                        }
                        cout << "Enter the score for a different number? Enter 1 if yes and 0 if no: ";
                        cin >> repeatSwitchCase;
                    }
                    break;
                }
                case 'F':
                case 'f':
                    cout << endl << "*** You have selected to record final exam grades for all students. ***" << endl;
                    break;
                case 'C':
                case 'c':
                    cout << endl << "*** You have selected to change a grade for a particular student. ***" << endl;
                    break;
                case 'G':
                case 'g':
                    cout << endl << "*** You have selected to calculate students' final grade. ***" << endl;
                    break;
                case 'O':
                case 'o':
                    cout << endl << "*** You have selected to output the grade data. ***" << endl;
                    break;
                case 'Q':
                case 'q':
                    cout << endl << "*** You have selected to quit the program. ***" << endl;
                    break;

            }
        }
    }

}
