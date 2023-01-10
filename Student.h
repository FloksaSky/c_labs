#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "String11.h"


typedef struct
{
	String name;
	String lastName;
	String goupTittle;
	int marks[3];
} Student;

Student StudentInit(char* name, char* lastName, char* groupTitle, int mark1, int mark2, int mark3)
{
	Student student;
	student.name = StringCopy(name);
	student.lastName = StringCopy(lastName);
	student.goupTittle = StringCopy(groupTitle);
	student.marks[0] = mark1;
	student.marks[1] = mark2;
	student.marks[2] = mark3;
	return student;
}

void StudentDelete(Student* student)
{
	if (student != NULL)
	{
		StringDelete(student->lastName);
		StringDelete(student->lastName);
		StringDelete(student->goupTittle);
	}
}

double StudentGetAvgMark(Student* student)
{
	if (student != NULL)
	{
		double sum = 0;
		for (int i = 0; i < 3; i++)
			sum += student->marks[i];
		return sum / 3;
	}
}

String StrudentToString(Student* student)
{
	if (student != NULL)
	{
		char* buffer = (char*)malloc(255 * sizeof(char));
		sprintf_s(buffer, 255, "|%20s|%20s|%20s|%10i|%10i|%10i|%10lf",
			student->name.symbols, student->lastName.symbols, student->goupTittle.symbols,
			student->marks[0], student->marks[1], student->marks[2],StudentGetAvgMark(student));
		return  StringCopy(buffer);
	}
	return StringInit(0);
}