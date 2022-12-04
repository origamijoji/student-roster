#include <iostream>
#include "student.h"
#include "roster.h"
using std::cout;

int main() {
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
		"A5,George,Sarac,gsarac2@wgu.edu,18,15,8,5,SOFTWARE"
	};
	const int numOfStudents = 5;
	Roster classRoster;
	
	for (int i = 0; i < numOfStudents; i++) {
		classRoster.parse(studentData[i]);
	}
	cout << "C867" << "\tC++" << "\t#010532540" << "\tGeorge Sarac\n";
	std::cout << "--------------------------------" << '\n';

	classRoster.printAll();
	std::cout << "--------------------------------" << '\n';

	classRoster.printInvalidEmails();
	std::cout << "--------------------------------" << '\n';

	for (int i = 0; i <= classRoster.lastIndex; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	std::cout << "--------------------------------" << '\n';

	classRoster.printByDegreeProgram(SOFTWARE);
	std::cout << "--------------------------------" << '\n';

	classRoster.remove("A3");
	std::cout << "--------------------------------" << '\n';
	classRoster.printAll();
	std::cout << "--------------------------------" << '\n';
	classRoster.remove("A3");
	std::cout << "--------------------------------" << '\n';

	return 0;
}