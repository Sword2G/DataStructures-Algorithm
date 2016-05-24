#include<stdio.h>

void printDigit(unsigned int n)
{
	printf("%d", n);
}

void printNumber(unsigned int n)
{
	if(n >= 10)
		printNumber(n / 10);
	printDigit(n % 10);
}
int main()
{
	unsigned int a = 123;

	printNumber(a);

	printf("\n");

	return 0;

}