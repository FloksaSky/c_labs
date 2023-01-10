#include <locale.h>
#include"DB.h"

void StudentTests()
{
	Student student = StudentInit("name", "lastname", "somegroup-1", 1, 2, 3);
	printf("avg:%f", StudentGetAvgMark(&student));
	printf("\n%s\n", StrudentToString(&student).symbols);
}

void DBTests()
{
	DB db = DBInit();
	DBAdd(&db, StudentInit("name1", "lastname", "somegroup-1", 1, 2, 3));
	DBAdd(&db, StudentInit("name2", "lastname", "somegroup-1", 1, 2, 3));
	DBAdd(&db, StudentInit("name3", "lastname", "somegroup-1", 1, 2, 3));
	DBDelete(&db, 1);
	DBPrint(&db,-1);
}

Student GetStudent()
{
	char name[255];
	char lastName[255];
	char group[255];
	int marks[3];
	printf("Name:\n");
	scanf_s("%s", name, 255);
	printf("Last name:\n");
	scanf_s("%s", lastName, 255);
	printf("Group:\n");
	scanf_s("%s", group, 255);
	printf("Grades(3 p.):\n");
	scanf_s("%i %i %i", &marks[0], &marks[1], &marks[2], 10);
	return StudentInit(name, lastName, group, marks[0], marks[1], marks[2]);
}

void PrintMenu()
{
	printf("\n");
	printf("1. View the spreadsheet\n");
	printf("2. Add an element\n");
	printf("3. Delete an element\n");
	printf("4. Output by average score\n");
	printf("5. Exit\n");
}

int main()
{
	setlocale(LC_ALL, "rus");
	//StudentTests();
	//DBTests();
	//GetStudent();
	DB db = DBInit();
	DBAdd(&db, StudentInit("name1", "lastname", "somegroup-1", 4, 5, 5));
	DBAdd(&db, StudentInit("name2", "lastname", "somegroup-1", 4, 4, 3));
	DBAdd(&db, StudentInit("name3", "lastname", "somegroup-1", 1, 2, 3));
	bool isStarted = true;
	while (isStarted)
	{
		//getc();
		//system("cls");
		int answer;
		PrintMenu();
		printf("\nSelect an item\n");
		scanf_s("%i", &answer, 2);
		switch (answer)
		{
		case 1:
			DBPrint(&db,-1);
			break;
		case 2:
			DBAdd(&db, GetStudent());
			break;
		case 3:
			printf("\nEnter the number of the item to be deleted from 0\n");
			scanf_s("%i", &answer, 255);
			DBDelete(&db, answer);
			break;
		case 4:
			DBPrint(&db, 4.5);
			break;
		case 5:
			isStarted = false;
			break;
		default:
			break;
		}
	}
	return 0;
}