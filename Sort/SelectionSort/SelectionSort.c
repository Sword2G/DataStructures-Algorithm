#include<stdio.h>

void swap(int * A, int i, int j)
{
	int temp; 

	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void PrintArrag(int *A, int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", A[i]);
	
	printf("\n");
}

void SelectionSort(int *A, int n)
{
	int i, min, j;

	for(i = 0; i < n-1; i++)
	{
		min = i;
		for(j = i+1; j < n; j++)
		{
			if(A[j] < A[min])
				min = j;
		}

		if(min != i)
			swap(A, i, min);

	}
}

int main()
{
	int A[] = {3, 4, 5, 7, 1, 8, 9, 2, 10, 6}; 

	printf("before sort...\n");
	PrintArrag(A, 10);;

	SelectionSort(A, 10);

	printf("after sort...\n");
	PrintArrag(A, 10);

	return 0;

}