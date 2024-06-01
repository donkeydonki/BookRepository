//
//  main.cpp
//

#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"

int main() {
    
    cout << "Scripting & Programming - Applications" << std::endl;
    cout << "Language: C++" << std::endl;
    cout << "Student ID: 011894470" << std::endl;
    cout << "Name: Sumika Helffrich" << std::endl << std::endl;
    
    
    const string studentData[] =
    
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,first,last,email@address.com,25,35,45,55,SOFTWARE"};
    
    const int numStudent = 5;
    Roster roster;
    
    for (int i = 0; i < numStudent; ++i) roster.parse(studentData[i]);
    cout << "Displaying all students: " << std::endl;
    roster.printAll();
    cout << std::endl;
    
    cout << "Displaying invalid emails: " << std::endl;
    roster.printInvalidEmails();
    cout << std::endl;    
    
    /* // BEFORE REVISION
    cout << "Displaying average days in course: " << std::endl;
    roster.printAverageDaysInCourse("");
    cout << std::endl; */
    
    // AFTER REVISION
    cout << "Displaying average days in course: " << std::endl;
     for (int i = 0; i < numStudent; ++i) {
         roster.printAverageDaysInCourse(roster.classRosterArray[i]->getStudentID()); 
     }
    cout << std::endl;
    
    cout << "Showing students in degree program: SOFTWARE" << std::endl;
    roster.printByDegreeProgram(SOFTWARE);
    cout << std::endl;
    
    cout << "Removing A3: " << std::endl;
    roster.remove("A3");
    cout << std::endl;
    roster.printAll();
    cout << std::endl;
    
    cout << "Removing A3 again: " << std::endl;
    roster.remove("A3");
    cout << std::endl;
    
    cout << "DONE" << std::endl;
    
    return 0;
}

