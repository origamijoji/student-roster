#pragma once
#include <iostream>
#include "degree.h"

using std::string;

extern int amtOfClasses;

class Student {
public:
	const static int numOfClasses = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int courseTimeArray[numOfClasses];
	DegreeProgram degreeProgram;

public:
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getCourseTimeArray();
	DegreeProgram getDegreeProgram();

	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setCourseTimeArray(int courseTimeArray[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int courseTimeArray[], DegreeProgram getDegreeProgram);
	~Student();

	void print();
};