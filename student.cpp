//
//  student.cpp
//  c867pa
//
//  Created by Connor Hillis on 8/4/22.
//
#include "student.h"
//creating the student objects
Student::Student(string studentID, string fName, string lName, string email,int age, int daysInCourse[], DegreeProgram degree)
{
    this->studentID = studentID;
    this->fName = fName;
    this->lName = lName;
    this->email = email;
    this->age =age;
    for(int i = 0; i < 3; i++) this->daysInCourse[i] = daysInCourse[i];
    this->degree = degree;
    
}

//getters
string Student::getID() {return this->studentID;}
string Student::getfName() {return this->fName;}
string Student::getlName() {return this->lName;}
string Student::getEmail() {return this->email;}
int Student::getAge() {return this ->age;}
const int* Student::getDaysInCourse() {return this->daysInCourse;}
DegreeProgram Student::getDegreeProgram() {return this->degree;}

//setters
void Student::setID(string ID){this->studentID = ID;}
void Student::setfName(string fName){this->fName = fName;}
void Student::setlName(string lName){this->lName = lName;}
void Student::setEmail(string email){this->email = email;}
void Student::setAge(int age){this->age = age;}
void Student::setDaysInCourse(const int daysInCourse[]){for(int i = 0; i < 3; i++) this->daysInCourse[i] = daysInCourse[i];}
void Student::setDegreeProgram(DegreeProgram degree) {this->degree= degree;}


//prints the header
void Student::printHeader()
{
    cout << "Student ID\t";
    cout << "First Name\t";
    cout << "Last Name\t";
    cout << "Email\t";
    cout << "Age\t";
    cout << "Days in Course\t";
    cout << "Degree Program\t";
    cout <<endl;
}

//printing the individual students
void Student::print()
{
    cout << this->studentID << '\t';
    cout << this->fName << '\t';
    cout << this->lName << '\t';
    cout << this->email << '\t';
    cout << this->age << '\t';
    cout << this->daysInCourse[0] << '\t';
    cout << this->daysInCourse[1] << '\t';
    cout << this->daysInCourse[2] << '\t';
    cout << degreeProgramStrings[(int)this->degree];
    cout << endl;
}

