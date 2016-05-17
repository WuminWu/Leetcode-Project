// ReverseVowelsOfString_CPP.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

bool isVowel(char s)
{
	if (s >= 'A'&& s <= 'Z')
		s += 'a' - 'A';
	return s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u';
}

string reverseVowels(string s) 
{
	int L = 0, R = s.length()-1;
	char tempChar = NULL;

	while (L < R)
	{
		while (L < R && !isVowel(s[L]))
			L++;
		while (L < R && !isVowel(s[R]))
			R--;
		tempChar = s[L];
		s[L] = s[R];
		s[R] = tempChar;

		L++;
		R--;
	}
	return s;
}


int _tmain(int argc, _TCHAR* argv[])
{
	string returnStr;
	returnStr = reverseVowels("Hello");
	printf("returnStr = %s\n", returnStr.c_str());

	returnStr = reverseVowels("LeetCode");
	printf("returnStr = %s\n", returnStr.c_str());

	returnStr = reverseVowels("sdfghjkl");
	printf("returnStr = %s\n", returnStr.c_str());

	system("pause");
	return 0;
}

