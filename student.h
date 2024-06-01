#pragma once
#ifndef student_h
#define student_h
#include <string>
#include <iostream>
#include <iomanip>
#include "degree.h"
#include <stdio.h>
using std::string;
using std::cout;
//  student.h
//  Class Roster_C867

class Student {
public:
    const static int daysInCourseArray = 3;
    
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse[daysInCourseArray];
    DegreeProgram degreeProgram;
    
public:
    // Parameterless onstructor
    Student();
    
    // Constructor with parameters
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);
    
    // Destructor
    ~Student();
    
    // Getters
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDaysInCourse();
    DegreeProgram getDegreeProgram();
    
    // Setters
    void setStudentID(string getStudentID);
    void setFirstName(string getFirstName);
    void setLastName(string getLastName);
    void setEmailAddress(string getEmailAddress);
    void setAge(int getAge);
    void setDaysInCourse(int daysInCourse[]);
    void setDegreeProgram(DegreeProgram getDegreeProgram);
    
    //Prints all student info
    void printAll();
    
    // Print fuction
    void print();
};

#endif // student_h
