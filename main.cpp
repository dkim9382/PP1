#include "GradeReport.h"
#include <iostream>
#include <fstream>

// Asks user for class data file name and uses it to create the grade report.
int main() {
	string input;
	string firstName;
	string lastName;
	string fileName;
	double grades[5];
	double grade;
	GradeReport report;

	cout << "Enter name of class data file: ";
	cin >> fileName;
	ifstream inFS(fileName);
	
	// Check to see if input file opened successfully. Exit program if not.
	if (inFS.is_open()) {
		cout << "\nSuccessfully opened " + fileName + "\n\n";
	}
	else {
		cout << "\nError opening " + fileName + "\n\n";
		return 1;
	}

	// Reads in class data one student at a time.
	while (inFS.peek() != EOF) {
		inFS >> firstName;
		inFS >> lastName;
		for (int i = 0; i < 5; ++i) {
			inFS >> grade;
			grades[i] = grade;
		}
		report.AddStudent(Student(firstName, lastName, grades));
	}

	report.PrintGradeReport();
}