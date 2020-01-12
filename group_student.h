#ifndef group_student_h
#define group_student_h

#include<stdio.h>
#include<algorithm>
#include<vector>
#include"student.h"

using namespace std;

class GroupStudent
{
private:
	int groupNumber;
	vector<Student*> listOfStudents;
public:
	GroupStudent(int number);
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
