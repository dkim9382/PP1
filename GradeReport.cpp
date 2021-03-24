#include "GradeReport.h"
#include <fstream>
#include <iostream>
#include <iomanip>

// Add Student to end of Grade Report.
void GradeReport::AddStudent(Student student) {
	students.push_back(student);
}

// Creates and outputs the grade report to GradeReport.txt.
void GradeReport::PrintGradeReport() const {
	double* grades;
	double studentHighestGrade = 0;
	double highestTestGrade = 0;
	double sumTestAverages = 0;
	double average;
	vector<Student> studentsHighestGrade;
	vector<vector<double>> testSums;
	
	ofstream outFS("GradeReport.txt");

	// Checks to see if output file was opened successfully. If not, function does not continue.
	if (outFS.is_open()) {
		cout << "Successfully started writing to GradeReport.txt\n\n";
	}
	else {
		cout << "Error writing to GradeReport.txt\n";
		return;
	}
	
	// Create header labels for output
	outFS << left;
	outFS << " ";
	outFS << setw(10) << "First";
	outFS << setw(15) << "Last";
	outFS << setw(10) << "Test 1";
	outFS << setw(10) << "Test 2";
	outFS << setw(10) << "Test 3";
	outFS << setw(10) << "Test 4";
	outFS << setw(15) << "Final";
	outFS << setw(10) << "Average";
	outFS << "Grade\n\n";

	outFS << fixed << setprecision(2);
	
	// Goes through each Student's data in Grade Report to calculate necessary output.
	for (size_t i = 0; i < students.size(); ++i) {

		// Output first and last name.
		outFS << " ";
		outFS << setw(10) << students.at(i).GetFirstName();
		outFS << setw(15) << students.at(i).GetLastName();

		grades = students.at(i).GetGrades();
		testSums.push_back(vector<double>());

		// Outputs test grades of Student.
		// 2D vector (testSums) used to keep track of all test scores for each test. Will be used to calculate the average of each test.
		for (int j = 0; j < 5; ++j) {
			testSums.at(i).push_back(grades[j]);
			outFS << setw(10) << grades[j];

			// Keeps track of highest test grade of all tests.
			if (grades[j] > highestTestGrade) {
				highestTestGrade = grades[j];
			}
		}

		average = students.at(i).GetAverage();
		sumTestAverages += average; // Used to find average of all tests.

		// Keep track of Student(s) with highest class grade.
		if (average > studentHighestGrade) {
			studentHighestGrade = average;
			studentsHighestGrade.clear();
			studentsHighestGrade.push_back(students.at(i));
		}
		else if (abs(average - studentHighestGrade) < DBL_EPSILON) {
			studentsHighestGrade.push_back(students.at(i));
		}

		// Output average and letter grade of each Student.
		outFS << "     " << setw(10) << average;
		outFS << setw(5) << students.at(i).GetLetterGrade() << "\n";
	}

	// Output average of each test.
	outFS << "\n";
	outFS << setw(26) << " Test average:";
	for (int i = 0; i < 5; ++i) {
		double total = 0.0;
		for (size_t j = 0; j < testSums.size(); ++j) {
			total += testSums.at(j).at(i);
		}
		double testAverage = total / static_cast<double>(testSums.size());
		outFS << setw(10) << testAverage;
	}

	// Output average of each test, highest grade of all tests, and Student(s) with highest class grade.
	outFS << "\n\n" << setw(81) << " Overall test average:  " << sumTestAverages / testSums.size();
	outFS << "\n\n Highest test grade:  " << highestTestGrade;
	outFS << "\n\n Student(s) with the highest class grade:  ";

	// Proper formatting in case multiple students are tied for highest class grade.
	for (size_t i = 0; i < studentsHighestGrade.size(); ++i) {
		if (i > 0) {
			outFS << ", ";
		}
		outFS << studentsHighestGrade.at(i).GetFullName();
	}

	cout << "Completed output to GradeReport.txt\n";
}