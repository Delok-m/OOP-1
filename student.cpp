#include"student.h"

Student::Student(string name)
{
	this->name = name;
	this->min_mark = 2 + rand() % 4;
}
void Student::addGroupNumber(int groupNumber)
{
	group_numbers.push_back(groupNumber);
}
void Student::deleteGroupNumber(int groupNumber)
{
	vector<int>::iterator position = find(group_numbers.begin(), group_numbers.end(), groupNumber);
	if (position != group_numbers.end()) {
		group_numbers.erase(position);
	}
}
string Student::getName()
{
	return this->name;
}
int Student::getMinMark()
{
	return this->min_mark;
}
int Student::getGroupCount()
{
	return this->group_numbers.size();
}
const vector<int>& Student::getGroupNumbers()
{
	return this->group_numbers;
}
void Student::setName(string name)
{
	this->name = name;
}
void Student::setMinMark(int minMark)
{
	this->min_mark = minMark;
}