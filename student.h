//
//  student.h
//  c867pa
//
//  Created by Connor Hillis on 8/4/22.
//
#include <iostream>
#include <iomanip>
#include "degree.h"

using std::string;
using std::cout;
using std::endl;

//initializing student class
class Student
{
private:
    string studentID;
    string fName;
    string lName;
    string email;
    int age;
    int daysInCourse[3];
    DegreeProgram degree;
public:
    Student();
    Student(string studentID, string fName, string lName,string email,int age, int daysInCourse[], DegreeProgram degree);
    
    //Getters
    string getID();
    string getfName();
    string getlName();
    string getEmail();
    int getAge();
    const int* getDaysInCourse();
    DegreeProgram getDegreeProgram();
    
    //setters
    void setID(string ID);
    void setfName(string fName);
    void setlName(string lName);
    void setEmail(string email);
    void setAge(int age);
    void setDaysInCourse(const int daysInCourse[]);
    void setDegreeProgram(DegreeProgram degree);
    static void printHeader();
    void print();
    
};

