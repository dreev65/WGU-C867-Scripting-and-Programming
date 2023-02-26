#include <iostream>

#include "roster.h"
using namespace std;

Roster::Roster() {
    this->maxSize = 0;
    this->lastIndex = -1;
    this->classRosterArray = nullptr;
}

Roster::Roster(int maxSize) {
    this->maxSize = maxSize;
    this->lastIndex = -1;
    this->classRosterArray = new Student * [maxSize];
}

void Roster::ParseAndAdd(string row) {
    int parseArray[Student::tableSize]{};
    DegreeProgram degreeProgram{};

    if (lastIndex < maxSize) {
        lastIndex++;
    }

    this->classRosterArray[lastIndex] = new Student();

//read studentID//
    int long delimiter = row.find(",");
    classRosterArray[lastIndex]->SetStudentID(row.substr(0, delimiter));

//read firstName//
    int long index = delimiter + 1;
    delimiter = row.find(",", index);
    classRosterArray[lastIndex]->SetFirstName(row.substr(index, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(delimiter) - index));

//read lastName//
    index = delimiter + 1;
    delimiter = row.find(",", index);
    classRosterArray[lastIndex]->SetLastName(row.substr(index, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(delimiter) - index));

//read emailAddress//
    index = delimiter + 1;
    delimiter = row.find(",", index);
    classRosterArray[lastIndex]->SetEmailAddress(row.substr(index, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(delimiter) - index));

//read age//
    index = delimiter + 1;
    delimiter = row.find(",", index);
    int x = stoi(row.substr(index, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(delimiter) - index));
    classRosterArray[lastIndex]->SetAge(x);

//read daysInCourse1//
    index = delimiter + 1;
    delimiter = row.find(",", index);
    parseArray[0] = stoi(row.substr(index, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(delimiter) - index));

//read daysInCourse2//
    index = delimiter + 1;
    delimiter = row.find(",", index);
    parseArray[1] = stoi(row.substr(index, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(delimiter) - index));

//read daysInCourse3//
    index = delimiter + 1;
    delimiter = row.find(",", index);
    parseArray[2] = stoi(row.substr(index, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(delimiter) - index));

//days left in course//
    classRosterArray[lastIndex]->SetDaysInCourse(parseArray);

//read degree program//
    index = delimiter + 1;
    if (row[index] == 'S') {
        if (row[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(index) + 1] == 'E') {
            classRosterArray[lastIndex]->SetDegreeProgram(SECURITY);
        }
        else if (row[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(index) + 1] == 'O') {
            classRosterArray[lastIndex]->SetDegreeProgram(SOFTWARE);
        }
        else {
            cerr << "Invalid degree." << endl;
            exit(-1);
        }
    }
    else if (row[index] == 'N') {
        classRosterArray[lastIndex]->SetDegreeProgram(NETWORK);
    }
    else {
        cerr << "Invalid degree." << endl;
        exit(-1);
    }
}

void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgam) {
    int arrayDaysInCourse[Student::tableSize]{};
        arrayDaysInCourse[0] = daysInCourse1;
        arrayDaysInCourse[1] = daysInCourse2;
        arrayDaysInCourse[2] = daysInCourse3;
    classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, arrayDaysInCourse, degreeProgam);
}

Student* Roster::GetStudent(int index) {
    return classRosterArray[index];
}

void Roster::PrintAll() {
    for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->Print();
}

bool Roster::Remove(string ID) {
    bool located = false;
    for (int i = 0; i <= lastIndex; i++) {
        if (this->classRosterArray[i]->GetStudentID() == ID) {
            located = true;
            delete this->classRosterArray[i];
            this->classRosterArray[i] = this->classRosterArray[lastIndex];
            lastIndex--;
        }
    }
    if (!located) {
        cout << "Student with ID " << ID << " not found." << endl;
    }
    return located;
}

void Roster::PrintAverageDaysInCourse(string studentID) {
    bool located = false;
    for (int i = 0; i <= lastIndex; i++) {
        if (this->classRosterArray[i]->GetStudentID() == studentID) {
            located = true;
            int* ptr = classRosterArray[i]->GetDaysInCourse();
            cout << "Average number of days left in class for " << studentID << " is " << (ptr[0] + ptr[1] + ptr[2]) / 3 << "\n";
        }
    }
    if (!located) {
        cout << "Student not found!\n";
    }
}

void Roster::PrintInvalidEmails() {
    cout << "Invalid email entries:\n";
    for (int i = 0; i < 5; i++) {
        string email = classRosterArray[i]->GetEmailAddress();
        if ((email.find("@") == string::npos || email.find(".") == string::npos) || (email.find(" ") != string::npos))
            cout << email << endl;
    }
}

void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) {
    cout << "Printing by degree " << DegreeProgramStrings[degreeProgram] << endl;
    for (int i = 0; i <= lastIndex; i++) {
        if (this->classRosterArray[i]->GetDegreeProgram() == degreeProgram) this->classRosterArray[i]->Print();
    }
}

Roster::~Roster() {
    delete[] classRosterArray;
}