#pragma once
#include "degree.h"
#include <string>
#include <iostream>
using namespace std;

class Student {

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int* arrayDaysInCourse;
	DegreeProgram degreeProgram;

public:

	//defualt constructor//
	Student();

	//constructor//
	Student(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int arrayDaysInCourse[],
		DegreeProgram degreeProgram
	);

public:
	const static int tableSize = 3;

	//setters for Strudent class//
	void SetStudentID(string studentID);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmailAddress(string emailAddress);
	void SetAge(int age);
	void SetDaysInCourse(int arrayDaysInCourse[]);
	void SetDegreeProgram(DegreeProgram degreeProgram);

	//getters for student class//
	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	int GetAge();
	int* GetDaysInCourse();
	DegreeProgram GetDegreeProgram();

	//print statement//
	void Print();

};

