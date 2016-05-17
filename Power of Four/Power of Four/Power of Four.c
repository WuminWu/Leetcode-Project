// Power of Four.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <stdbool.h>

bool isPowerOfFour(int num) 
{
	return num > 0 && (num & (num - 1)) == 0 && (num & 0x55555555) != 0;
}

int main(int argc, char* argv[])
{
	bool answer = isPowerOfFour(64);
	printf("answer = %d\n", answer);
	system("pause");
	return 0;
}

