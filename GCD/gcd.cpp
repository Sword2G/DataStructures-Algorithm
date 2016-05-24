#include<stdio.h>

unsigned int Gcd(unsigned int M, unsigned int N)
{
	unsigned int rem;
	while( N > 0)
	{
		rem = M % N;
		M = N;
		N = rem;
	}

	return M;
}

int main()
{
	unsigned int M = 1989;
	unsigned int N = 1590;

	printf("Gcd(%d, %d) = %d\n", M, N, Gcd(M, N));

	return 0;
}