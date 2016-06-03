/*
Given nums = [-2, 0, 3, -5, 2, -1]
sumRange(0, 2) -> 1
sumRange(2, 5) -> - 1
sumRange(0, 5) -> - 3
*/

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

struct NumArray 
{
	int arraySum;
};

/* Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize) 
{
	struct NumArray *initArray;
	initArray = (struct NumArray *) malloc(numsSize * sizeof(struct NumArray));
	for (int i = 0; i < numsSize; i++)
		(initArray + i)->arraySum = 0;

	initArray->arraySum = *nums;
	for (int i = 1; i < numsSize; i++)
		(initArray + i)->arraySum = ((initArray + i -1)->arraySum) + *(nums + i);

	return initArray;
}

int sumRange(struct NumArray* numArray, int i, int j) 
{
	if (i == 0)
		return ((numArray + j)->arraySum);
	else
		return (numArray + j)->arraySum - (numArray + i - 1)->arraySum;
}

/* Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray) 
{
	free(numArray);
}

// Your NumArray object will be instantiated and called as such:
// struct NumArray* numArray = NumArrayCreate(nums, numsSize);
// sumRange(numArray, 0, 1);
// sumRange(numArray, 1, 2);
// NumArrayFree(numArray);
int main(int argc, char* argv[])
{
	struct NumArray* numArray;
	int nums[] = { -2, 0, 3, -5, 2, -1 };

	numArray = NumArrayCreate(nums, sizeof(nums)/sizeof(int));

	int sumOne = sumRange(numArray, 0, 2);
	printf("sumOne = %d\n", sumOne);

	int sumTwo = sumRange(numArray, 2, 5);
	printf("sumTwo = %d\n", sumTwo);

	int sumThree = sumRange(numArray, 0, 5);
	printf("sumThree = %d\n", sumThree);

	NumArrayFree(numArray);
	system("pause");
	return 0;
}

