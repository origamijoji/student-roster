#include "roster.h"
#include <string>

void Roster::parse(string studentData) {
	int rhs = studentData.find(",");
	string studentID = studentData.substr(0, rhs);
	int lhs = rhs + 1;

	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);
	lhs = rhs + 1;

	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);
	lhs = rhs + 1;

	rhs = studentData.find(",", lhs);
	string emailAddress = studentData.substr(lhs, rhs - lhs);
	lhs = rhs + 1;

	rhs = studentData.find(",", lhs);
	string age = studentData.substr(lhs, rhs - lhs);
	lhs = rhs + 1;

	int daysInCourse1;
	rhs = studentData.find(",", lhs);
	daysInCourse1 = std::stoi(studentData.substr(lhs, rhs - lhs));
	lhs = rhs + 1;

	int daysInCourse2;
	rhs = studentData.find(",", lhs);
	daysInCourse2 = std::stoi(studentData.substr(lhs, rhs - lhs));
	lhs = rhs + 1;

	int daysInCourse3;
	rhs = studentData.find(",", lhs);
	daysInCourse3 = std::stoi(studentData.substr(lhs, rhs - lhs));

	DegreeProgram degreeProgram = NONE;
	if (studentData.back() == 'K') degreeProgram = NETWORK;
	if (studentData.back() == 'Y') degreeProgram = SECURITY;
	if (studentData.back() == 'E') degreeProgram = SOFTWARE;

	add(studentID, firstName, lastName, emailAddress, std::stoi(age), daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int courseTimeArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, courseTimeArray, degreeProgram);
}

void Roster::remove(string studentID) {
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			std::cout << "REMOVED STUDENT #" << classRosterArray[i]->getStudentID() << '\n';
			if (i < lastIndex -1) {
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numOfStudents - 1];
				classRosterArray[numOfStudents - 1] = temp;
			}
			Roster::lastIndex--;
			return;
		}
	}
	std::cout << "STUDENT #"<< studentID <<" NOT FOUND" << '\n';
}

void Roster::printAll() {
	// loop through array, call print() on all students
	for (int i = 0; i <= Roster::lastIndex; i++) {
		classRosterArray[i]->print();
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	std::cout << "ALL STUDENTS WITH DEGREE PROGRAM " << degreeStrings[degreeProgram] << '\n';
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	std::cout << "AVERAGE DAYS IN COURSE FOR STUDENT #" << studentID << ": ";
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			int sum = 0;
			sum += classRosterArray[i]->getCourseTimeArray()[0];
			sum += classRosterArray[i]->getCourseTimeArray()[1];
			sum += classRosterArray[i]->getCourseTimeArray()[2];
			sum /= Student::numOfClasses;
			std::cout << sum << '\n';
			return;
		}
	}
	std::cout << "STUDENT NOT FOUND" << '\n';
}

void Roster::printInvalidEmails() {
	std::cout << "INVALID EMAILS" << '\n';
	for (int i = 0; i <= Roster::lastIndex; i++) {
		string thisEmail = classRosterArray[i]->getEmailAddress();
		if (thisEmail.find(" ") != std::string::npos) {
			std::cout << thisEmail << '\n';
			continue;
		}
		if (thisEmail.find("@") == std::string::npos) {
			std::cout << thisEmail << '\n';
			continue;
		}
		if (thisEmail.find(".") == std::string::npos) {
			std::cout << thisEmail << '\n';
			continue;
		}
	}
}

Roster::~Roster() {
	std::cout << "DESTRUCTOR CALLED" << '\n';
	for (int i = 0; i < numOfStudents; i++) {
		std::cout << "DESTROYED STUDENT #" << classRosterArray[i]->getStudentID() << '\n';
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}