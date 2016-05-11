// ReverseString.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

char* reverseString(char* s, char destiStr[])
{
	int stringLen = strlen(s);
	int i = 0, j = 0;
	
	for (i = stringLen - 1, j = 0; i >= 0; i--, j++)
		destiStr[j] = *(s + i);
	destiStr[j] = '\0';
	printf("destiStr = %s\n", s);

	return destiStr;
}

int main(int argc, char* argv[])
{
	char sourceStr[100] = {"Hello"};
	char destiStr[sizeof(sourceStr)] = { 0 };

	char *revString = reverseString(sourceStr, destiStr);
	printf("revString = %s\n", revString);
	
	system("pause");
	return 0;
}

