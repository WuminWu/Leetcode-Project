// ReverseString.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

char* reverseString(char* s)
{
	int stringLen = strlen(s);
	int i = 0, j = 0;
	char *tempStr = (char *)malloc(strlen(s) * sizeof(char) +1);
	
	for (i = stringLen - 1, j = 0; i >= 0; i--, j++)
		tempStr[j] = *(s + i);
	tempStr[j] = '\0';

	s = tempStr;
	return s;
}

int main(int argc, char* argv[])
{
	char *revString = reverseString("hello");
	printf("revString = %s\n", revString);
	
	system("pause");
	return 0;
}

