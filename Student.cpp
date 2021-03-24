#include "Student.h"

// Parameterized constructor for Student.
Student::Student(string firstName, string lastName, double grades[]) {
	this->firstName = firstName;
	this->lastName = lastName;
	for (int i = 0; i < 5; ++i) {
		this->grades[i] = grades[i];
	}
}

// Getter function for Student's first name.
string Student::GetFirstName() const {
	return firstName;
}

// Getter function for Student's last name.
string Student::GetLastName() const {
	return lastName;
}

// Getter function for Student's full name. 
string Student::GetFullName() const {
	return firstName + " " + lastName;
}

// Returns an array copy of Student's grades.
double* Student::GetGrades() const {
	double* tempGrades = new double[5];
	for (int i = 0; i < 5; ++i) {
		tempGrades[i] = grades[i];
	}
	return tempGrades;
}

// Returns Student's test average with final counting twice.
double Student::GetAverage() const {
	return (grades[0] + grades[1] + grades[2] + grades[3] + grades[4] * 2) / 6.0;
}

// Returns letter grade of Student's test average.
char Student::GetLetterGrade() const {
	double average = GetAverage();
	char grade;

	if (average >= 90.0) {
		grade = 'A';
	}
	else if (average >= 80.0) {
		grade = 'B';
	}
	else if (average >= 70.0) {
		grade = 'C';
	}
	else if (average >= 60.0) {
		grade = 'D';
	}
	else {
		grade = 'F';
	}

	return grade;
}