#include<stdio.h>

void PrintArrag(int *A, int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", A[i]);
	
	printf("\n");
}

void InsertSort(int *A, int n)
{
	int i, j;
	int temp;

	for(i = 1; i < n; i++)
	{
		temp = A[i];

		for(j = i; j >=0 && A[j - 1] > temp; j--)
		{
			A[j] = A[j - 1];
		}

		A[j] = temp;
	}
}

int main()
{
	int A[] = {3, 4, 5, 7, 1, 8, 9, 2, 10, 6}; 

	printf("before sort...\n");
	PrintArrag(A, 10);;

	InsertSort(A, 10);

	printf("after sort...\n");
	PrintArrag(A, 10);

	return 0;

}