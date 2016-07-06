#include<stdio.h>

int jumpFloor0(int n)
{
	if(n <= 0)
		return -1;
	else if(n == 1)
		return 1;
	else if(n == 2)
		return 2;
	else
		return jumpFloor0(n - 1) + jumpFloor0(n - 2);
}


int jumpFloor1(int n)
{
	int first = 1, second = 2;

	while(--n)
	{
		second = first + second;
		first = second - first;
	}

	return first;
}


int main()
{
	int n = 10;

	printf("%d\n", jumpFloor0(n));
	printf("%d\n", jumpFloor1(n));

	return 0;
}


