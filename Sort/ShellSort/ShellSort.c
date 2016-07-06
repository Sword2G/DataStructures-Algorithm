#include<stdio.h>

void PrintArrag(int *A, int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", A[i]);
	
	printf("\n");
}

void ShellSort(int *A, int n)
{
	int i, j, temp, increament;

	for(increament = n / 2; increament > 0; increament /= 2)
	{
		for(i = increament; i < n; i++)
		{
			temp = A[i];

			for(j = i; j >= 0 && A[j - increament] > temp; j -= increament)
			{
				A[j] = A[j - increament];
			}

			A[j] = temp;
		}
	}
}

int main()
{
	int A[] = {3, 4, 5, 7, 1, 8, 9, 2, 10, 6}; 

	printf("before sort...\n");
	PrintArrag(A, 10);;

	ShellSort(A, 10);

	printf("after sort...\n");
	PrintArrag(A, 10);

	return 0;

}