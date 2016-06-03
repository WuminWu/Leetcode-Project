// ReverseVowelsOfString.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isVowels(char s)
{
	if (s >='A'&& s <='Z')
		s += 'a' - 'A';
	return s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u';
}

char* reverseVowels(char* s) 
{
	int L = 0, R = strlen(s) - 1;
	char tempChar = NULL;
	char *Array = (char *)malloc(strlen(s)*sizeof(char)+1);
	for (int i = 0; i < strlen(s); i++)
		Array[i] = *(s + i);

	while (L < R)
	{
		while (L < R && !isVowels(Array[L]))
			L++;
		while (L < R && !isVowels(Array[R]))
			R--;
		if (L < R)
		{
			tempChar = Array[L];
			Array[L] = Array[R];
			Array[R] = tempChar;
		}
		L++;
		R--;
	}
	*(Array + strlen(s)) = '\0';

	return Array;
}

int main(int argc, char* argv[])
{
	char *returnStr = NULL;
	returnStr = reverseVowels("Hello");
	printf("returnStr = %s\n", returnStr);

	returnStr = reverseVowels("LeetCode");
	printf("returnStr = %s\n", returnStr);

	returnStr = reverseVowels("sdfghjkl");
	printf("returnStr = %s\n", returnStr);

	free(returnStr);
	system("pause");
	return 0;
}

