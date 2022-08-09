//
//  main.cpp
//  c867pa
//
//  Created by Connor Hillis on 8/3/22.
//

#include "roster.h"


int main() {
    std::cout << "Course: C867 Scripting and Programin Applications\n";
    std::cout << "Language: C++\n";
    std::cout << "Student ID: 111111\n";
    std::cout << "Name: Connor Hillis\n";
    cout <<endl;
    cout <<endl;
    const string studentData[] =
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Connor,Hillis,chil499@wgu.edu,24, 25,30,35,SOFTWARE"};
    
    //initializing roster and entering all data
    Roster roster;
    for (int i = 0; i < 5; i++) roster.parse(studentData[i]);
    //calling all functions to print and remove
    roster.printAll();
    roster.printInvalidEmail();
    roster.printAverageDays("A3");
    roster.removeByID("A3");
    roster.printAll();
    roster.removeByID("A3");
    roster.printByDegree(DegreeProgram::SOFTWARE);
    
    return 0;
}
