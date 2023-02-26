#pragma once
#include "student.h"
#include <iostream>
#include <string>

class Roster {

    public:
        int lastIndex;
        int maxSize = 5;

//array of pointers//
        Student** classRosterArray; 

//default constructor//
        Roster();
        Roster(int maxSize);

        void ParseAndAdd(string row);
        void Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogam);

        Student* GetStudent(int index);

//removal of studentID//
        
    
//print functions//
        void PrintAll();
        bool Remove(string studentID);
        void PrintAverageDaysInCourse(string studentID);
        void PrintInvalidEmails();
        void PrintByDegreeProgram(DegreeProgram degreeprogram);
    
//destructor//
        ~Roster();
};
