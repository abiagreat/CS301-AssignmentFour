//
// Created by Mario O Salinas and Abia Khan
//

#include <iostream>
#include <string>

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
    Student();
    void PutName(string);
    void PutIDNumber(int);
    void PutAssignmentScores(int, int, int);
    void PutTestScores(int, int, int);
    void PutFinalExamScores(int, int, int);
    string GetName();
    int GetIDNumber();
    int GetAssignmentScore(int, int);
    int GetTestScores(int, int);
    int GetFinalExamScores(int, int);
};

Student::Student() {
    arraySize = 0;
    studentName = " ";
    studentIDNumber = 0;
}

void Student::PutName(string name) {
     studentName = name;
}

void Student::PutIDNumber(int num) {
    studentIDNumber = num;
}

void Student::PutAssignmentScores(int score, int assignmentNumber, int numberOfAssignments) {
    arraySize = numberOfAssignments;
    studentAssignmentScores = new int[arraySize]; // Allocate memory for assignment scores
    studentAssignmentScores[assignmentNumber] = score;
}

void Student::PutTestScores(int score, int testNumber, int numberOfTests) {
    arraySize = numberOfTests;
    studentTestScores = new int[arraySize]; // Allocate memory for test scores
    studentTestScores[testNumber] = score;
}

void Student::PutFinalExamScores(int score, int finalExamNumber, int numberOfFinalExams) {
    arraySize = numberOfFinalExams;
    studentFinalExamScores = new int[arraySize]; // Allocate memory for final exam scores
    studentFinalExamScores[finalExamNumber] = score;
}

string Student::GetName() {
    return studentName;
}

int Student::GetIDNumber() {
    return studentIDNumber;
}

int Student::GetAssignmentScore(int size, int assignmentNumber) {
    arraySize = size;
    int score = studentAssignmentScores[assignmentNumber];
    return score;
}

int Student::GetTestScores(int size, int testNumber) {
    arraySize = size;
    int score = studentAssignmentScores[testNumber];
    return score;
}

int Student::GetFinalExamScores(int size, int finalExamNumber) {
    arraySize = size;
    int score = studentAssignmentScores[finalExamNumber];
    return score;
}
