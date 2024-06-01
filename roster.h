//
//  roster.h
//
#pragma once
#include "student.h"

#ifndef roster_h
#define roster_h

#include <stdio.h>

class Roster {
public:
    int lastIndex = -1;
    const static int numStudent = 5;
    Student* classRosterArray[numStudent];
    
public:
    

    void parse(string row);
    void add (string studentID, string firstName, string lastName, string emailAddress, int age, int daysInClass1, int daysInClass2, int daysInClass3, DegreeProgram degreeProgram);
    void printAll();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    void printInvalidEmails();
    void printAverageDaysInCourse(string studentID);
    void remove(string studentID);
    ~Roster();
};
#endif /* roster_h */

