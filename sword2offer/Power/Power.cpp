#include<stdio.h>

double Power(double base, int exponent)
{
	double result = 1.0;

	if(base == 0)
		return 0.0;
	if(exponent == 0)
		return 1;

	while(exponent--)
	{
		result *= base;
	}

	if(exponent > 0)
		return result;
	else if(exponent < 0)
		return 1 / result;
}