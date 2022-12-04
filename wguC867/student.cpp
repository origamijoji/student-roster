#include "student.h";
using std::cout;

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < numOfClasses; i++) {
		courseTimeArray[i] = 0;
	}
	this->degreeProgram = NONE;
}
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int courseTimeArray[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < numOfClasses; i++) {
		this->courseTimeArray[i] = courseTimeArray[i];
	}
	this->degreeProgram = degreeProgram;
}
Student::~Student() {
	// blank destructor
}

string Student::getStudentID() {
	return this->studentID;
}
string Student::getFirstName() {
	return this->firstName;
}
string Student::getLastName() {
	return this->lastName;
}
string Student::getEmailAddress() {
	return this->emailAddress;
}
int Student::getAge() {
	return this->age;
}
int* Student::getCourseTimeArray() {
	return this->courseTimeArray;
}
DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}

void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setCourseTimeArray(int courseTimeArray[]) {
	for (int i = 0; i < numOfClasses; i++) {
		this->courseTimeArray[i] = courseTimeArray[i];
	}
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

void Student::print() {
	cout << getStudentID() << '\t';
	cout << getFirstName() << '\t';
	cout << getLastName() << '\t';
	cout << getEmailAddress() << '\t';
	cout << getAge() << '\t';
	cout << getCourseTimeArray()[0] << ',';
	cout << getCourseTimeArray()[1] << ',';
	cout << getCourseTimeArray()[2] << '\t';
	cout << degreeStrings[(int)getDegreeProgram()] << '\n';
}
