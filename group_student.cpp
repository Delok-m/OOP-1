#include "group_student.h"

StudentGroup::StudentGroup(int number)
{
	this->groupNumber = number;
}

void StudentGroup::addStudent(Student* student)
{
	if (listOfStudents.size() < 20) {
		if (find(listOfStudents.begin(), listOfStudents.end(), student) != listOfStudents.end()) {
		}
		else {
			listOfStudents.push_back(student);
			student->addGroupNumber(this->groupNumber);
		}
	}
	else {
		cout << "Can't be more 20 students in a group" << endl;
	}
}
void StudentGroup::deleteStudent(Student* student)
{
	vector<Student*>::iterator position = find(listOfStudents.begin(), listOfStudents.end(), student);
	if (position != listOfStudents.end()) {
		student->deleteGroupNumber(this->groupNumber);
		listOfStudents.erase(position);
	}
	else
		cout << "Error." << endl;
}

int StudentGroup::getGroupNumber()
{
	return this->groupNumber;
}
void StudentGroup::setGroupNumber(int groupNumber)
{
	this->groupNumber = groupNumber;
}
Student* StudentGroup::getStudentByName(string& name)
{
	int i = 0;
	for (i = 0; listOfStudents.size(); i++)
	{
		if (listOfStudents[i]->getName() == name) {
			return listOfStudents[i];
		}
	}
	return nullptr;
}
vector<Student*> StudentGroup::getListOfStudents()
{
	return listOfStudents;
}
vector<Student*> StudentGroup::getListOfStudentsSortedByName()
{
	vector<Student*> tempVector = listOfStudents;
	if (listOfStudents.empty())
	{
		cout << "No students in group " << this->groupNumber  << endl;
		return tempVector;
	}
	else {
		sort(tempVector.begin(), tempVector.end(), [](Student* a, Student* b)
		{
			return a->getName()[0] < b->getName()[0];
		});
	}

	return tempVector;
}
vector<Student*> StudentGroup::getListOfStudentsSortedByMarks()
{
	vector<Student*> tempVector = listOfStudents;
	if (listOfStudents.empty())
	{
		cout << "No students in group " << this->groupNumber  << endl;
		return tempVector;
	}
	else {
		sort(tempVector.begin(), tempVector.end(), [](Student* a, Student* b)
		{
			return a->getMinMark() > b->getMinMark();
		});
	}

	return tempVector;
}