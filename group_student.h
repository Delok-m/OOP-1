#ifndef group_student_h
#define group_student_h

#include <stdio.h>
#include <algorithm>
#include <vector>
#include "Student.h"

using namespace std;

class StudentGroup
{
private:
	int groupNumber;
	vector<Student*> listOfStudents;
public:
	void addStudent(Student* student);
	Student* getStudentByName(string &name);
	void deleteStudent(Student* student);
	int getGroupNumber();
	void setGroupNumber(int groupNumber);
	vector<Student*> getListOfStudents();
	vector<Student*> getListOfStudentsSortedByName();
	vector<Student*> getListOfStudentsSortedByMarks();
	StudentGroup(int number);
};
#endif 
