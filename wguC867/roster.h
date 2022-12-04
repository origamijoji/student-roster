#pragma once
#include "student.h"

class Roster {
private:
	const static int numOfStudents = 5;
public:
	int lastIndex = -1;
	Student* classRosterArray[numOfStudents];
	void parse(string data);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	~Roster();
};