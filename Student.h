//
// Created by Mario Salinas and Abia Khan
//

#ifndef CS301_ASSIGNMENTFOUR_STUDENT_H
#define CS301_ASSIGNMENTFOUR_STUDENT_H

#include <string>
#include <iostream>
using namespace std;

class Student {
private:
    int arraySize;
    string studentName;
    int studentIDNumber;
    int studentAssignmentScores[arraySize];
    int studentTestScores[arraySize];
    int studentFinalExamScores[arraySize];
public:
    Student();
    void PutName(string);
    void PutIDNumber(int);
    void PutAssignmentScores(int, int);
    void PutTestScores(int, int);
    void PutFinalExamScores(int, int);
    string GetName();
    int GetIDNumber();
    int GetAssignmentScore(int, int);
    int GetTestScores(int);
    int GetFinalExamScores(int);
};


#endif //CS301_ASSIGNMENTFOUR_STUDENT_H
