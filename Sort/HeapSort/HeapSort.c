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

void PercDown(int *A, int i, int n)
{
	int temp, child;

	for(temp = A[i]; 2 * i < n; i = child)
	{
		child = 2 * i;

		if(child != n-1 && A[child] < A[child + 1])
			child++;
		if(temp < A[child])
			A[i] = A[child];
		else
			break;
	}

	A[i] = temp;
}

void HeapSort(int *A, int n)
{
	int i;

	for(i = n / 2; i >= 0; i--)
	{
		PercDown(A, i, n);
	}

	for(i = n - 1; i > 0; i--)
	{
		swap(A, 0, i);
		PercDown(A, 0, i);
	}
}

int main()
{
	int A[] = {3, 4, 5, 7, 1, 8, 9, 2, 10, 6}; 

	printf("before sort...\n");
	PrintArrag(A, 10);;

	HeapSort(A, 10);

	printf("after sort...\n");
	PrintArrag(A, 10);

	return 0;

}