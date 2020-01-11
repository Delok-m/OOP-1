#ifndef student_h
#define student_h

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class Student
{
private:
	string name;
	int min_mark;
	vector<int> group_numbers;
public:

	void addGroupNumber(int groupNumber);
	void deleteGroupNumber(int groupNumber);
	string getName();
	void setName(string name);
	void setMinMark(int minMark);
	int getGroupCount();
	int getMinMark();
	const vector<int>& getGroupNumbers();
	Student(string name);
};
#endif 
