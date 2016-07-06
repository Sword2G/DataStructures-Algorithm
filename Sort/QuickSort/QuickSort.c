#include<stdio.h>
#include<stdlib.h>

#define cutOff 3

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

int Median3(int *A, int left, int right)
{

	int center = (left + right) / 2;

	if(A[left] > A[center])
		swap(A, left, center);
	if(A[left] > A[right])
		swap(A, left, right);
	if(A[center] > A[right])
		swap(A, center, right);

	swap(A, center, right - 1);

	return A[right - 1];
}

void Qsort(int *A, int left, int right)
{
	int i, j, pivot;

	if(left + cutOff <= right)
	{
		pivot = Median3(A, left, right);

		i = left;
		j = right - 1;

		for(;;)
		{
			while(A[++i] < pivot);
			while(A[--j] > pivot);
			if(i < j)
				swap(A, i, j);
			else
				break;
		}

		swap(A, i, right - 1);

		Qsort(A, left, i - 1);
		Qsort(A, i + 1, right);
	}
	else
	{
		InsertSort(A + left, right - left + 1);
	}
}

void Qselect(int *A, int k, int left, int right)
{
	int i, j, pivot;

	if(left + cutOff <= right)
	{
		pivot = Median3(A, left, right);

		printf("\n%d\n", pivot);
		i = left;
		j = right - 1;

		for(;;)
		{
			while(A[++i] < pivot);
			while(A[--j] > pivot);
			if(i < j)
				swap(A, i, j);
			else
				break;
		}

		//μú k D?μ?êy??±ê?ak-1￡? k - 1 < i , k - 1 > i
		if(k - 1 < i)
			Qselect(A, k, left, i - 1);
		else if(k - 1 > i)
			Qselect(A, k, i + 1, right);
	}
	else
	{
		InsertSort(A + left, right - left + 1);
	}
}

void QuickSort(int *A, int n)
{
//	Qselect(A, 6, 0, n - 1);
	Qsort(A, 0, n - 1);
}


int main()
{
	int A[] = {3, 4, 5, 7, 1, 8, 9, 2, 10, 6}; 

	printf("before sort...\n");
	PrintArrag(A, 10);;

	QuickSort(A, 10);

	printf("after sort...\n");
	PrintArrag(A, 10);

	return 0;

}