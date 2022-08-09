//
//  roster.cpp
//  c867pa
//
//  Created by Connor Hillis on 8/4/22.
//
#include "roster.h"

//adding to roster function
void Roster::add(string studentID, string fName, string lName, string email,int age,int day1, int day2, int day3, DegreeProgram degree)
{
    int dayArray[3] = {day1,day2,day3};
    classRosterArray[++lastIndex] = new Student(studentID, fName, lName,email,age, dayArray, degree);
}

//parsing function for the student data
void Roster::parse(string studentData)
{
    double limit = studentData.find(',');
    string studentID = studentData.substr(0,limit);
    double base = limit +1;
    
    limit = studentData.find(',',base);
    string fName = studentData.substr(base,limit - base);
    base = limit +1;
    
    limit = studentData.find(',',base);
    string lName = studentData.substr(base,limit - base);
    base = limit +1;
    
    limit = studentData.find(",",base);
    string email = studentData.substr(base,limit - base);
    base = limit +1;
    
    limit = studentData.find(",",base);
    int age = stoi(studentData.substr(base,limit - base));
    base = limit +1;
    
    limit = studentData.find(",",base);
    int day1 = stoi(studentData.substr(base,limit - base));
    base = limit +1;
    
    limit = studentData.find(",",base);
    int day2 = stoi(studentData.substr(base,limit - base));
    base = limit +1;
    
    limit = studentData.find(",",base);
    int day3 = stoi(studentData.substr(base,limit - base));
    base = limit +1;
    
    DegreeProgram degree = DegreeProgram::SOFTWARE;
    if(studentData.back()=='K') degree = DegreeProgram::NETWORK;
    else if(studentData.back()=='Y') degree = DegreeProgram::SECURITY;

    
    add(studentID,fName,lName, email,age, day1, day2, day3, degree);
}


void Roster::printAll()
{
    cout << "Printing all students";
    cout << endl;
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print();
    cout << endl;
}

void Roster::printInvalidEmail()
{
    cout << "Printing invalid email address's" << endl;
    for (int i = 0; i<=Roster::lastIndex; i++)
    {
        string email = classRosterArray[i]->getEmail();
        string fName = classRosterArray[i]->getfName();
        string lName = classRosterArray[i]->getlName();
        if(email.find(' ') != string::npos || email.find('@') == string::npos || email.find('.') == string::npos)
            cout << fName <<" " << lName << "'s email is invalid: " << email << endl;
    }
    cout << endl;
}

void Roster::printAverageDays(string studentID)
{
    for(int i =0; i<=Roster::lastIndex;i++)
    {
        if(classRosterArray[i]->getID()==studentID)
           {
               cout << "Average days of courses for student " << studentID << ": ";
               cout << ((classRosterArray[i]->getDaysInCourse()[0] + classRosterArray[i]->getDaysInCourse()[1] + classRosterArray[i]->getDaysInCourse()[2]) / 3);
               cout << endl;
           };
    }
    cout << endl;
}

void Roster::printByDegree(DegreeProgram degree)
{
    Student::printHeader();
    for(int i = 0; i<=Roster::lastIndex;i++){
        if(Roster::classRosterArray[i]->getDegreeProgram() == degree)
        {
            classRosterArray[i]->print();
        }
    }
    cout << endl;
}

void Roster::removeByID(string studentID)
{
    cout <<"Attemping to remove student " << studentID <<endl;
    bool found = false;
    for(int i = 0; i<=Roster::lastIndex;i++)
    {
        if(classRosterArray[i]->getID()==studentID)
        {
            found = true;
            Student* temp = classRosterArray[i];
            classRosterArray[i] = classRosterArray[numStudents-1];
            classRosterArray[numStudents-1] = temp;
            Roster::lastIndex--;
        }
    }
    if(found)
    {
        cout << "Student " << studentID <<" has been removed";
        cout << endl;
        cout << endl;
    }
    else
    {
        cout << "There is not a student with that ID";
        cout << endl;
        cout << endl;
    }
}

Roster::~Roster()
{
    for(int i = 0; i < numStudents;i++)
    {
        cout << "Destructed student " << classRosterArray[i]->getID() <<endl;
        delete classRosterArray[i];
        classRosterArray[i]=nullptr;
    }
}

