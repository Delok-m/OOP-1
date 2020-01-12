#ifndef student_h
#define student_h

#include<stdio.h>
#include<vector>
#include<iostream>

using namespace std;

class Student
{
private:
	string name;
	int min_mark;
	vector<int> group_numbers;
public:
	Student(string name);
	void addGroupNumber(int groupNumber);
	void deleteGroupNumber(int groupNumber);
	string getName();
	int getMinMark();
	int getGroupCount();
	const vector<int>& getGroupNumbers();
	void setName(string name);
	void setMinMark(int minMark);
};
#endif 
