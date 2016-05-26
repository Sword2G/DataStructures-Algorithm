#include<stdio.h>

void Swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int *A, int low, int high)
{
	int pivotkey;
	pivotkey = A[low];

	while(low < high)
	{
		while(low < high && A[high] > pivotkey)
			high--;
		Swap(&A[low], &A[high]);
		while(low < high && A[low] < pivotkey)
			low++;
		Swap(&A[low], &A[high]);
	}

	return low;
}

void Qsort(int *A, int low, int high)
{
	int pivot;

	if(low < high)
	{
		pivot = Partition(A, low, high);

		Qsort(A, low, pivot - 1);
		Qsort(A, pivot + 1, high);
	}
}

void PrintArrag(int *A, int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", A[i]);
	
	printf("\n");
}

int main()
{
	int A[] = {3, 4, 5, 7, 1, 8, 9, 2, 10, 6}; 

	printf("before sort...\n");
	PrintArrag(A, 10);;

	Qsort(A, 0, 10);

	printf("after sort...\n");
	PrintArrag(A, 10);

	return 0;

}