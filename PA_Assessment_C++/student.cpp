#include "student.h"
#include <string>
#include <iostream>
using namespace std;

//default constructor//
    Student::Student() {
        this->studentID = "";
        this->firstName = "";
        this->lastName = "";
        this->emailAddress = "";
        this->age = 0;
        this->arrayDaysInCourse = new int[tableSize];
        for (int i = 0; i < tableSize; i++) this->arrayDaysInCourse[i] = 0;
            this->degreeProgram = SOFTWARE; 
    }

//constructor//
    Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram) {
        this->studentID = studentID;
        this->firstName = firstName;
        this->lastName = lastName;
        this->emailAddress = emailAddress;
        this->age = age;
        this->arrayDaysInCourse = new int[tableSize];
        for (int i = 0; i < tableSize; i++) this->arrayDaysInCourse[i] = arrayDaysInCourse[i];
            this->degreeProgram = degreeProgram;
    }

//setter functions//
    void Student::SetStudentID(string studentID) {
        this->studentID = studentID;
    }
    void Student::SetFirstName(string firstName) {
        this->firstName = firstName;
    }
    void Student::SetLastName(string lastName) {
        this->lastName = lastName;
    }
    void Student::SetEmailAddress(string emailAddress) {
        this->emailAddress = emailAddress;
    }
    void Student::SetAge(int age) {
        this->age = age;
    }
    void Student::SetDaysInCourse(int arrayDaysInCourse[]) {
        for (int i = 0; i < tableSize; i++) {
            this->arrayDaysInCourse[i] = arrayDaysInCourse[i];
        }
    }
    void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
        this->degreeProgram = degreeProgram;
    }

//getter functions//
    string Student::GetStudentID() {
        return studentID;
    }
    string Student::GetFirstName() {
        return firstName;
    }
    string Student::GetLastName() {
        return lastName;
    }
    string Student::GetEmailAddress() {
        return emailAddress;
    }
    int Student::GetAge() {
        return age;
    }
    int* Student::GetDaysInCourse() {
        return arrayDaysInCourse;
    }
    DegreeProgram Student::GetDegreeProgram() {
        return degreeProgram;
    }

//print function//
    void Student::Print() {
    cout << GetStudentID() << '\t' << GetFirstName() << '\t' << GetLastName() << '\t' << GetAge() << '\t';
    int* arrayDaysInCourse = GetDaysInCourse();
    cout << '\t' << "Days in course: " << "{" << arrayDaysInCourse[0] << ", " << arrayDaysInCourse[1] << ", " << arrayDaysInCourse[2] << "}" << '\t' << "Degree Program: " << DegreeProgramStrings[GetDegreeProgram()] << endl;
}

