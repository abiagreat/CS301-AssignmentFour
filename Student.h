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
    // from stack overflow: "If you do want a variable-sized array, then the standard way of doing
    // this is to use heap allocation. In other words, you need to declare studentAssignmentScores to be a pointer
    // to an integer array, which you will allocate during runtime."
    int *studentAssignmentScores = new int[arraySize];
    int *studentTestScores = new int[arraySize];
    int *studentFinalExamScores = new int[arraySize];
public:
void PutName(string);
    void PutIDNumber(int);
    void PutAssignmentScores(int, int, int);
    void PutTestScores(int, int, int);
    void PutFinalExamScores(int, int, int);
    string GetName();
    int GetIDNumber();
    int GetAssignmentScore(int, int);
    int GetTestScores(int);
    int GetFinalExamScores(int);
    Student();
};

Student::Student() {
    arraySize = 0;
    studentName = " ";
    studentIDNumber = 0;
    studentAssignmentScores = nullptr;
    studentTestScores = nullptr;
    studentFinalExamScores = nullptr;
    }

Student::~Student() {
    delete[] studentAssignmentScores;
    delete[] studentTestScores;
    delete[] studentFinalExamScores;
    }

#endif //CS301_ASSIGNMENTFOUR_STUDENT_H
