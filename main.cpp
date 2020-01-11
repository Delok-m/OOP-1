#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <locale>
#include <ctime>
#include "student.h"
#include "group_student.h"
#include "windows.h"

using namespace std;

int main(int argc, const char * argv[]) {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	Student* AllStudentsList[19];
	StudentGroup* AllGroupsList[5];
	string names[19] = { 
		"Рашета Полина Захаровна",
		"Салтыкова Варвара Захаровна",
		"Кондракова Жанна Михеевна",
		"Коченков Бронислав Геннадиевич",
		"Миронов Андриян Кондратиевич",
		"Гречко Злата Александровна",
		"Гаврин Бронислав Владиславович",
		"Агеева Софья Игнатиевна",
		"Суснина Анна Ивановна",
		"Головченко Лаврентий Левович",
		"Гущин Тихон Трофимович",
		"Луков Адам Дмитриевич",
		"Власьев Святослав Капитонович",
		"Едемский Федот Венедиктович",
		"Верица Тимофей Ефремович",
		"Жаркин Кирилл Валерьянович",
		"Лукашенко Ипполит Натанович",
		"Караулова Вера Юлиевна",
		"Яковенко Давид Денисович"
	};
	int groups[5] = { 7091,7411,7401,7371,7311 };
	for (int i = 0; i < 19; i++)
	{
		Student* student = new Student(names[i]);
		AllStudentsList[i] = student;
	}
	for (int i = 0; i < 5; i++)
	{
		StudentGroup* studentGroup = new StudentGroup(groups[i]);
		AllGroupsList[i] = studentGroup;
	}
	cout << "Students: " << endl;
	for (int i = 0; i < 19; i++)
	{
		cout << i + 1 << ". " << AllStudentsList[i]->getName() << endl;
	}
	for (int i = 0; i < 19; i++)
	{
		int indGroup = rand() % 5;
		int indStud = rand() % 19;

		AllGroupsList[indGroup]->addStudent(AllStudentsList[indStud]);
	}

	cout << "Groups: ";
	for (int i = 0; i < 5; i++)
	{
		cout << AllGroupsList[i]->getGroupNumber() << "  ";
	}

	filebuf fb;
	fb.open("out.txt", ios::out);
	ostream out(&fb);
	for (int i = 0; i < 5; i++)
	{
		vector<Student*> tempVector = AllGroupsList[i]->getListOfStudentsSortedByMarks();
		if (tempVector.empty())
		{
			out << "No students in group" << AllGroupsList[i]->getGroupNumber();
		}
		else {
			out << "Students from the group " << AllGroupsList[i]->getGroupNumber() << ":" << endl;
			for (int i = 0; i < tempVector.size(); i++)
			{
				out << i + 1 << ". " << tempVector[i]->getName() << " MinMark: " << tempVector[i]->getMinMark() << endl;
			}
		}
	}
	fb.close();


	while (true) {
		cout << endl << "Group number(To finish, enter '0'): " << endl;
		int inputGroup;
		cin >> inputGroup;
		if (inputGroup == 0)
		{
			break;
		}
		int tempGroupInd = 0;
		while (tempGroupInd < 5)
		{
			if (AllGroupsList[tempGroupInd]->getGroupNumber() == inputGroup) {
				break;
			}
			tempGroupInd++;
		}
		if (tempGroupInd == 5)
		{
			cout << "Error.";
			continue;
		}
		else
		{
			vector<Student*> tempStudents = AllGroupsList[tempGroupInd]->getListOfStudents();
			if (tempStudents.empty())
			{
				cout << "No students in this group" << endl;
				continue;
			}
			for (int i = 0; i < tempStudents.size(); i++)
			{
				cout << i + 1 << "." << tempStudents[i]->getName() << endl;
			}
		}
		cout << "Name of the student to remove from the group('0' to return): " << endl;
		string strNameInput;
		cin.ignore();
		getline(cin, strNameInput);
		if (strNameInput == "0")
		{
			continue;
		}
		cout << strNameInput << endl;


		for (int i = 0; i < 19; i++)
		{
			if (strNameInput == names[i])
			{
				AllGroupsList[tempGroupInd]->deleteStudent(AllGroupsList[tempGroupInd]->getStudentByName(strNameInput));
				cout << "Student removed from the group" << endl;
				break;
			}
			if (i == 18)
			{
				cout << "Error." << endl;;
			}
		}
	}
	return 0;
}