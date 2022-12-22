#include <String.h>
#include <locale.h>

char* ReadLine(size_t length)
{
	char* inputStr = (char*)calloc(length, sizeof(char));
	if (scanf_s("%[^\n]s", inputStr, length) < 0)
	{
		free(inputStr);
		return NULL;
	}
	return inputStr;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct
{
	char* symbols;
	size_t length;
} String;

String StringInit(size_t length)
{
	String result;
	if (length > 0) {
		result.symbols = (char*)calloc(length, sizeof(char));
		result.length = length;
	}
	else {
		result.symbols = (char*)calloc(1, sizeof(char));
		result.length = 1;
		result.symbols[0] = '\0';
	}
	return result;
}

void StringDelete(String str)
{
	free(str.symbols);
}

int StringGetLength(char* str)
{
	if (str == NULL)
		return 0;
	int length = 0;
	for (int i = 0;; i++)
	{
		if (str[i] == '\0')
			break;
		length++;
	}
	return length;
}

String StringCopy(char* str)
{
	String result;
	result.length = strlen(str);
	result.symbols = (char*)calloc(result.length + 1, sizeof(char));
	for (int i = 0; i < result.length; i++)
	{
		result.symbols[i] = str[i];
	}
	return result;
}

int StringCompare(String str1, String str2)
{
	if (str1.length > str2.length)
	{
		return 1;
	}
	else if (str1.length < str2.length)
	{
		return -1;
	}
	else
	{
		for (int i = 0; i < str1.length; i++)
		{
			if (str1.symbols[i] > str2.symbols[i])
			{
				return 1;
			}
			else if (str1.symbols[i] < str2.symbols[i])
			{
				return -1;
			}
		}
		return 0;
	}
}

void StringAdd(String* str, char c)
{
	if (str->length == 0)
	{
		StringDelete(*str);
		str->symbols = (char*)calloc(2, sizeof(char));
		str->length += 2;
	}
	else
	{
		str->symbols = (char*)realloc(str->symbols, (++(str->length)) * sizeof(char));
	}
	str->symbols[str->length - 2] = c;
	str->symbols[str->length - 1] = '\0';
}


bool IsStringSimpleContains(char* str, char c) {
	if (str == NULL)
		return false;
	for (size_t i = 0; i < strlen(str); i++)
	{
		if (str[i] == c)
			return true;
	}
	return false;
}


bool IsStringContains(String* str, char c) {
	if (str == NULL)
		return false;
	return IsStringSimpleContains(str->symbols, c);
}


bool StringIsNumber(String* str) {
	if (str == NULL)
		return false;
	const char* alphabet = "1234567890.+-";
	int commaCounter = 0;
	for (size_t i = 0; i < StringGetLength(str->symbols); i++)
	{
		if ((str->symbols[i] == '-' || str->symbols[i] == '+') && i != 0)
			return false;
		if (str->symbols[i] == '.' && i == 0)
			return false;
		if (str->symbols[i] == '.' && i == StringGetLength(str->symbols) - 1)
			return false;
		if (str->symbols[i] == '.')
			commaCounter++;
		if (commaCounter > 1)
			return false;
		if (!IsStringSimpleContains(alphabet, str->symbols[i]))
			return false;
	}
	return true;
}


String GetLongestUniqueStr(String str) {
	String uniqueStr = StringInit(0);
	for (int i = 0; i < str.length; i++) {
		String buffer = StringInit(0);
		for (int j = i; j < str.length; j++) {
			if (!IsStringContains(&buffer, str.symbols[j]))
				StringAdd(&buffer, str.symbols[j]);
			else {
				if (buffer.length > uniqueStr.length) {
					StringDelete(uniqueStr);
					uniqueStr = StringCopy(buffer.symbols);
				}
				break;
			}
		}
		if (buffer.length > uniqueStr.length)
		{
			StringDelete(uniqueStr);
			uniqueStr = StringCopy(buffer.symbols);
		}
		StringDelete(buffer);
	}
	return uniqueStr;
}



#include <Windows.h>
#include <conio.h>
int main() {
	
	printf("Input string:\n");
	String str = StringCopy(ReadLine(1024));
	String  uniqueStr = GetLongestUniqueStr(str);
	printf("Most long unique string: %s", uniqueStr.symbols);
	return 0;
}
