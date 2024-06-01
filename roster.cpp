//
//  roster.cpp
//
#include <iostream>
#include "roster.h"
using namespace std;


void Roster::parse(string studentData) {
    
    DegreeProgram degreeProgram = SOFTWARE;
    if (studentData.back() == 'Y') degreeProgram = SECURITY;
    else if (studentData.back() == 'K') degreeProgram = NETWORK;
    
    int rhs = studentData.find(",");
    string studentID = studentData.substr(0,rhs);
    
    int lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string firstName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lastName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string emailAddress = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int age = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInClass1 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInClass2 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInClass3 = stoi(studentData.substr(lhs, rhs - lhs));
    
    add(studentID, firstName, lastName, emailAddress, age, daysInClass1, daysInClass2, daysInClass3, degreeProgram);
    
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInClass1, int daysInClass2, int daysInClass3, DegreeProgram degreeProgram) {
    
    int daysInCourseArray[3] = { daysInClass1,daysInClass2,daysInClass3 };
    
    classRosterArray[++lastIndex] = new Student (studentID, firstName, lastName, emailAddress, age, daysInCourseArray, degreeProgram);
}

/* BEFORE REVISION
 void Roster::printAll() {
 
 for (int i = 0; i <= Roster::lastIndex; ++i) {
 
 cout << classRosterArray[i]->getStudentID(); cout << '\t';
 cout << classRosterArray[i]->getFirstName(); cout << '\t';
 cout << classRosterArray[i]->getLastName(); cout << '\t';
 cout << classRosterArray[i]->getEmailAddress(); cout << '\t';
 cout << classRosterArray[i]->getAge(); cout << '\t';
 cout << "{";
 cout << classRosterArray[i]->getDaysInCourse()[0]; cout << ",";
 cout << classRosterArray[i]->getDaysInCourse()[1]; cout << ",";
 cout << classRosterArray[i]->getDaysInCourse()[2];
 cout << "}" << '\t';
 cout << degreeProgramString[classRosterArray[i]->getDegreeProgram()] << std::endl;
 
 }
 } */

// AFTER REVISION
void Roster::printAll() {
    for (int i = 0; i < numStudent; ++i) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->Student::print();
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i <= Roster::lastIndex; ++i) {
        if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
    }
    cout << std::endl;
}

void Roster::printInvalidEmails() {
    bool any = false;
    for (int i = 0; i <= Roster::lastIndex; ++i) {
        string validEmail = (classRosterArray[i]->getEmailAddress());
        if (validEmail.find(' ') != string::npos || validEmail.find('.') == string::npos || validEmail.find('@') == string::npos) {
            
            any = true;
            cout << validEmail << " - " << classRosterArray[i]->getStudentID() << " is invalid. "<< std::endl;
        }
    }
    if (!any) cout << "None" << std::endl;
}

/* BEFORE REVISION
 void Roster::printAverageDaysInCourse(string studentID) {
 for (int i = 0; i <= Roster::lastIndex; ++i) {
 cout << "Student ID: " << classRosterArray[i]->getStudentID() << ", ";
 cout << "average days in course is: ";
 cout << (classRosterArray[i]->getDaysInCourse()[0] +
 classRosterArray[i]->getDaysInCourse()[1] +
 classRosterArray[i]->getDaysInCourse()[2]) / 3;
 cout << std::endl;
 
 }
 cout << std::endl;
 } */


// AFTER REVISION
void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i <= numStudent; ++i) {
        if (studentID == classRosterArray[i]->Student::getStudentID()) {
            int daysInCourse1 = (classRosterArray[i]->getDaysInCourse()[0]);
            int daysInCourse2 = (classRosterArray[i]->getDaysInCourse()[1]);
            int daysInCourse3 = (classRosterArray[i]->getDaysInCourse()[2]);
            int avgDaysInCourse = (daysInCourse1 + daysInCourse2 + daysInCourse3) / 3;
            cout << "StudentID: " << studentID << ", average days in course is: " << avgDaysInCourse << endl;
        }
    }
}


void Roster::remove(string studentID) {
    bool success = false;
    for (int i = 0; i <= Roster::lastIndex; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            success = true;
            if (i < numStudent - 1) {
                for (int j = i; j < numStudent - 1; ++j) {
                    classRosterArray[j] = classRosterArray[j + 1];
                }
                classRosterArray[numStudent - 1] = nullptr;
                Roster::lastIndex--;
            } else {
                classRosterArray[i] = nullptr;
            }
            Roster::lastIndex--;
            break;
        }
    }
    if (success) {
        cout << studentID << " removed from roster." << std::endl;
    } else {
        cout << studentID << " not found." << std::endl;
    }
}

Roster::~Roster() {
    cout << "Destructor called" << std::endl;
    for (int i = 0; i < numStudent; ++i) {
        cout<< "Deleting student: " << i + 1 << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
