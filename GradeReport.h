#ifndef GRADEREPORT_H
#define GRADEREPORT_H

#include "Student.h"
#include <vector>

class GradeReport {
	private:
		vector<Student> students;
	public:
		void AddStudent(Student student);
		void PrintGradeReport() const;
};

#endif