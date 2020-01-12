#ifndef group_student_h
#define group_student_h

#include<stdio.h>
#include<algorithm>
#include<vector>
#include"Student.h"

using namespace std;

class StudentGroup
{
private:
	int groupNumber;
	vector<Student*> listOfStudents;
public:
	StudentGroup(int number);
	void addStudent(Student* student);
	void deleteStudent(Student* student);
	int getGroupNumber();
	Student* getStudentByName(string &name);
	vector<Student*> getListOfStudents();
	vector<Student*> getListOfStudentsSortedByName();
	vector<Student*> getListOfStudentsSortedByMarks();
	void setGroupNumber(int groupNumber);
};
#endif 
