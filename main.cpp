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
    int displayCommandMenu = 1;    // chose whether to display the processing commands menu
    char command = 'I';         // operation to be executed. initialized to 'I' as a dummy place-holder

    cout << "Enter the name of the input file (hint: it's Grades.trn): ";
    cin >> inputFileName;
    inputFile.open(inputFileName.c_str());

    cout << "Enter the name of the output file (hint: it's Grades.dat): ";
    cin >> outputFileName;
    outputFile.open(outputFileName.c_str());

    if (!inputFile.good()) {
        cout << "I/O error. Can't find the input file! \n";
        exit(2);
    }

    // test output file
    outputFile << "*** Semester Grade Book ***" << endl << endl;

    while (displayCommandMenu != 0) {
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

        switch (command) {
            case 'S':
            case 's':
                cout << "*** You have selected to set up for a new semester. ***" << endl;
                outputFile << "Initializing data for a new semester... " << endl;


                // define variables
                int numAssignments, numTests, numFinalExams;
                float assignmentWeight, testWeight, examWeight;


                // prompt the user for int values
                cout << "Enter the number of semester assignments: ";
                cin >> numAssignments;
                while (numAssignments < 0 || numAssignments > 6) {
                    cout << "!! Error: You must enter a number between 0 and 6. Enter the number of semester assignments: " << endl;
                    cin >> numAssignments;
                }
                outputFile << "Number of assignments this semester: " << numAssignments << endl;

                cout << "Enter the number of tests: ";
                cin >> numTests;
                while (numTests < 0 || numTests > 4) {
                    cout << "!! Error: You must enter a number between 0 and 4. Enter the number of semester assignments: " << endl;
                    cin >> numTests;
                }
                outputFile << "Number of tests this semester: " << numTests << endl;

                cout << "Enter the number of final exams: ";
                cin >> numFinalExams;
                while (numFinalExams < 0 || numFinalExams > 1) {
                    cout << "!! Error: You must enter either 0 or 1. Enter the number of semester assignments: " << endl;
                    cin >> numFinalExams;
                }
                outputFile << "Number of final exams this semester: " << numFinalExams << endl;

                // prompt the user for float values
                cout << "Enter the relative weight of assignments as a decimal: ";
                cin >> assignmentWeight;
                cout << "Enter the relative weight of tests as a decimal: ";
                cin >> testWeight;
                cout << "Enter the relative weight of the final exam as a decimal: ";
                cin >> examWeight;
                while (assignmentWeight + testWeight + examWeight != 1.0) {
                    cout << "!! Error: The sum total of your relative weights must equal 1.0. " << endl << "The sum of your relative weights "
                    << "does not equal zero. Try again." << endl;
                    cout << "Enter the relative weight of assignments as a decimal: ";
                    cin >> assignmentWeight;
                    cout << "Enter the relative weight of tests as a decimal: ";
                    cin >> testWeight;
                    cout << "Enter the relative weight of the final exam as a decimal: ";
                    cin >> examWeight;
                }
                outputFile << "Assignment weight: " << assignmentWeight << endl;
                outputFile << "Test weight: " << assignmentWeight << endl;
                outputFile << "Exam weight: " << examWeight << endl;


                cout << "Return to the command instruction menu? Enter 1 if yes, enter 0 if no: ";
                cin >> displayCommandMenu;
                break;
            case 'A':
            case 'a': {
                // i use brackets here so that the program will allow me to initialize my integer variables
                // inside of this case
                cout << endl << "*** You have selected to add a new student. ***" << endl;
                outputFile << endl << "Initializing student data..." << endl;

                int studentIDNumber;
                int repeatSwitchCase = 1;
                while (repeatSwitchCase != 0) {
                    cin.ignore();
                    cout << "Enter the student's first and last name seperated by a space: ";
                    getline(cin, studentName);
                    cout << "Enter the student's ID number: ";
                    cin >> studentIDNumber;

                    outputFile << "Student name: " << studentName << endl;
                    outputFile << "Student ID number: " << studentIDNumber << endl;

                    cout << "Enter another student name? Enter 1 for yes or 0 for no: ";
                    cin >> repeatSwitchCase;
                }

                cout << "Return to the command instruction menu? Enter 1 if yes, enter 0 if no: ";
                cin >> displayCommandMenu;
                break;
            }
            case 'P':
            case 'p':
                {
              cout << endl << "*** You have selected to record programming assignment grades for all students. ***" << endl;

             // Add code here to prompt the user for the program number to be recorded.
            int programNumber;
            cout << "Enter the program number to be recorded: ";
            cin >> programNumber;

            // Verify that the entered program number is valid.
            while (programNumber >= numAssignments || programNumber < 0) {
                cout << "!! Error: Invalid program number. Enter a valid program number: ";
                cin >> programNumber;
                }
    
            // Now, loop through each student and record their grade for the selected program.
            for (int studentIndex = 0; studentIndex < numberOfStudents; studentIndex++) {
            // Prompt for the student's grade for the specified program.
                int programGrade;
                cout << "Enter the grade for " << students[studentIndex].studentName << " for program " << programNumber << ": ";
                cin >> programGrade;

                 // Assign the grade to the appropriate student's record.
                students[studentIndex].programGrades[programNumber] = programGrade;
                }

                cout << "Programming assignment grades have been recorded for all students." << endl;
        
                cout << "Return to the command instruction menu? Enter 1 if yes, enter 0 if no: ";
                cin >> displayCommandMenu;
                break;
            }
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
                        cout << "!! Error: Invalid test number. You cannot input a number less than zero or a number " << endl
                             << "greater than the number of tests you have assigned to your students. Try again."
                             << endl;
                        cout << "Enter the testNumber for which you will enter a grade: ";
                        cin >> testNumber;
                    }
                    cout << "Enter the score for a different number? Enter 1 if yes and 0 if no: ";
                    cin >> repeatSwitchCase;
                }


                cout << "Return to the command instruction menu? Enter 1 if yes, enter 0 if no: ";
                cin >> displayCommandMenu;
                break;
            }
            case 'F':
            case 'f':
                cout << endl << "*** You have selected to record final exam grades for all students. ***" << endl;


                cout << "Return to the command instruction menu? Enter 1 if yes, enter 0 if no: ";
                cin >> displayCommandMenu;
                break;
            case 'C':
            case 'c':
            {
                cout << endl << "*** You have selected to change a grade for a particular student. ***" << endl;

                // Prompt the user to enter the student number.
                int studentNumber;
                cout << "Enter the student number (0-based index) for whom you want to change a grade: ";
                cin >> studentNumber;

                // Verify that the entered student number is valid.
                while (studentNumber < 0 || studentNumber >= numberOfStudents) {
                        cout << "!! Error: Invalid student number. Enter a valid student number: ";
                        cin >> studentNumber;
                    }

                // Prompt the user to specify the type of grade to change (P, T, or F).
                char gradeType;
                cout << "Enter the grade type to change (P for Programming, T for Test, F for Final Exam): ";
                cin >> gradeType;

                // Validate the entered grade type.
                while (gradeType != 'P' && gradeType != 'p' && gradeType != 'T' && gradeType != 't' && gradeType != 'F' && gradeType != 'f') {
                cout << "!! Error: Invalid grade type. Enter a valid grade type (P, T, or F): ";
                cin >> gradeType;
                    }

                // Prompt the user to enter the new grade.
                int newGrade;
                cout << "Enter the new grade: ";
                cin >> newGrade;

                // Depending on the grade type, update the corresponding grade for the selected student.
                if (gradeType == 'P' || gradeType == 'p') {
                // Programming assignment grade
                students[studentNumber].programGrades[programNumber] = newGrade;
                    } else if (gradeType == 'T' || gradeType == 't') {
                // Test grade
                // You may need to prompt for the test number as well.
                // Similar to how you did it for 'P'.
                    } else if (gradeType == 'F' || gradeType == 'f') {
                    // Final exam grade
                // You may need to prompt for the final exam grade here.
                    }

                cout << "Grade for " << students[studentNumber].studentName << " has been updated." << endl;

                cout << "Return to the command instruction menu? Enter 1 if yes, enter 0 if no: ";
                cin >> displayCommandMenu;
                 break;
                        }
            case 'G':
            case 'g':
    cout << endl << "*** You have selected to calculate students' final grade. ***" << endl;

    // Loop through each student and calculate the final grade.
    for (int studentIndex = 0; studentIndex < numberOfStudents; studentIndex++) {
        // Initialize variables to store the sum of program and test grades.
        int programSum = 0;
        int testSum = 0;

        // Calculate the sum of program grades.
        for (int programIndex = 0; programIndex < numAssignments; programIndex++) {
            programSum += students[studentIndex].programGrades[programIndex];
        }

        // Calculate the sum of test grades.
        for (int testIndex = 0; testIndex < numTests; testIndex++) {
            testSum += students[studentIndex].testGrades[testIndex];
        }

        // Calculate the final grade as the weighted sum of program and test grades.
        float finalGrade = (programSum * assignmentWeight + testSum * testWeight) * 100;

        // Store the final grade in the student's record.
        students[studentIndex].finalGrade = finalGrade;
    }

    cout << "Final grades have been calculated and stored for all students." << endl;

    cout << "Return to the command instruction menu? Enter 1 if yes, enter 0 if no: ";
    cin >> displayCommandMenu;
    break;

            case 'O':
            case 'o':
                cout << endl << "*** You have selected to output the grade data. ***" << endl;


                cout << "Return to the command instruction menu? Enter 1 if yes, enter 0 if no: ";
                cin >> displayCommandMenu;
                break;
            case 'Q':
            case 'q':
                string line;
                cout << endl << "*** You have selected to quit the program. ***" << endl;
                // save information onto Grades.trn by copying each line of Grades.dat onto Grades.trn
                cout << "Saving your sessions data. please don't stop the program." << endl;
                while (getline(inputFile, line)) {
                    outputFile << line << endl;
                }
                cout << "Your data has been saved onto your grade book. Program will now close." << endl;

                displayCommandMenu = 0;
                break;
        }
    }

}
