#include <stdio.h>

#include <stdlib.h>

#include <assert.h>


#include "func.h"

#define SIZE 5

float test1()
{
	float a[SIZE] = {3, 1, 2, -4, 3};
	float *ae;
	float result;

	ae = a + SIZE;
	result = func(a, ae);

	return result;
}


float test2()
{
	int flag;
	float a[SIZE] = {3, 1, 2, 4, 2};
	float *ae;
	float result;

	ae = a + SIZE;
	result = func(a, ae);

	return result;
}


int main()
{
	assert(test1() == -12);
	printf("\nTest 1 finished successful.");

	assert(test2() == 84);
	printf("\nTest 2 finished successful.");

	return 0;
}