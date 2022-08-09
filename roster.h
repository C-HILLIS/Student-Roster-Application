//
//  roster.h
//  c867pa
//
//  Created by Connor Hillis on 8/4/22.
//


#pragma once
#include "student.h"
//initalizing the roster class and all its functions
class Roster
{
private:
    //counter
    int lastIndex =-1;
    const static int numStudents = 5;
    //pointer to roster
    Student* classRosterArray[numStudents];
public:
    
    void parse(string row);
    void add(string ID, string fName, string lName, string email,int age,int day1, int day2, int day3, DegreeProgram degree);
    void printAll();
    void printInvalidEmail();
    void printByDegree(DegreeProgram degree);
    void printAverageDays(string studentID);
    void removeByID(string studentID);
    ~Roster();
    
};



