#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
	private:
		string firstName;
		string lastName;
		double grades[5] = { 0,0,0,0,0 };
	public:
		Student(string firstName, string lastName, double grades[]);
		string GetFirstName() const;
		string GetLastName() const;
		string GetFullName() const;
		double* GetGrades() const;
		double GetAverage() const;
		char GetLetterGrade() const;
};

#endif