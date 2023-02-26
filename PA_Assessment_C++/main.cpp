#include <iostream>
#include "roster.h"
using namespace std;

int main() {

    int numStudents = 5;

    const string studentData[5] =
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Daniel,Reeve,dreev65@wgu.edu,22,35,25,45,SOFTWARE",};

//Roster class//
    Roster* classRoster = new Roster(numStudents);
    for (int i = 0; i < numStudents; i++) {
        classRoster->ParseAndAdd(studentData[i]);
    }

//print personal course information//
    cout << "Scripting and Programming - Applications C867" << endl;
    cout << "C++" << endl;
    cout << "#001990892" << endl;
    cout << "Daniel Reeve" << endl << endl;

//call print functions//
    cout << "Printing Roster: " << endl;
    classRoster->PrintAll();
    cout << endl << endl;

    classRoster->PrintInvalidEmails();
    cout << endl << endl;

    cout << "Average days left in course: " << endl;
    for (int i = 0; i < numStudents; i++) {
        classRoster->PrintAverageDaysInCourse(classRoster->GetStudent(i)->GetStudentID());
    }
    cout << endl << endl;

    classRoster->PrintByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << endl << endl;

    cout << "Remove student A3: " << endl;
    classRoster->Remove("A3");
    cout << endl << endl;

    cout << "Printing Roster: " << endl;
    classRoster->PrintAll();
    cout << endl << endl;

    cout << "Remove student A3: " << endl;
    classRoster->Remove("A3");
    cout << endl << endl;;

    return 0;
}