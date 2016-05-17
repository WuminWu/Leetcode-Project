// Power of Three.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include <stdbool.h>

bool isPowerOfThree(int n)
{
	if (n == 1)
		return true;
	else if (n <= 0)
		return false;

	return (n%3)==0 && isPowerOfThree(n/3);
}

int _tmain(int argc, _TCHAR* argv[])
{
	bool answer = isPowerOfThree(9);
	printf("answer = %d\n", answer);
	system("pause");
	return 0;
}

