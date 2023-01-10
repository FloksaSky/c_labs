#include "Student.h"


typedef struct
{
	Student* items;
	size_t length;
}DB;

DB DBInit()
{
	DB db;
	db.items = NULL;
	db.length = 0;
	return db;
}


void DBAdd(DB* db, Student student)
{
	if (db != NULL)
	{
		if (db->items == NULL)
			db->items = (Student*)calloc(++db->length, sizeof(Student));
		else
			db->items = (Student*)realloc(db->items, ++db->length * sizeof(Student));
		db->items[db->length - 1] = student;
	}
}

void DBDelete(DB* db, int index)
{
	if (db != NULL && db->items != NULL)
	{
		for (int i = index; i < db->length - 1; i++)
		{
			db->items[i] = db->items[i + 1];
		}
		db->items = (Student*)realloc(db->items, --db->length * sizeof(Student));
	}
}

void DBPrint(DB* db, double avg)
{
	printf("|%20s|%20s|%20s|%10s|%10s|%10s|%10s\n", "Name", "Last name", "Group", "Grade 1", "Grade 2", "Grade 3", "Average");
	if (db != NULL && db->items != NULL)
	{
		for (size_t i = 0; i < db->length; i++)
		{
			if (avg != -1)
			{
				if (StudentGetAvgMark(&db->items[i]) > avg)
					printf("%s\n", StrudentToString(&db->items[i]).symbols);
			}
			else
			{
				printf("%s\n", StrudentToString(&db->items[i]).symbols);
			}
		}
	}
}


