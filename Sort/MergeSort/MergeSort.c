#include<stdio.h>
#include<stdlib.h>

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

void Merge(int *A, int *tempArray, int Lpos, int Rpos, int RightEnd)
{
	int i, nums, tempPos, LeftEnd;
	tempPos = Lpos;
	nums = RightEnd - Lpos + 1;
	LeftEnd = Rpos - 1;

	while(Lpos <= LeftEnd && Rpos <= RightEnd)
	{
		if(A[Lpos] <= A[Rpos])
			tempArray[tempPos++] = A[Lpos++];
		else
			tempArray[tempPos++] = A[Rpos++];
	}

	while(Lpos <= LeftEnd)
		tempArray[tempPos++] = A[Lpos++];
	while(Rpos <= RightEnd)
		tempArray[tempPos++] = A[Rpos++];

	for(i = 0; i < nums; i++,RightEnd--)
		A[RightEnd] = tempArray[RightEnd];

}

void MSort(int* A, int *tempArray, int left, int right)
{
	int center;

	if(left < right)
	{
		center = (left + right) / 2;

		MSort(A, tempArray, left, center);
		MSort(A, tempArray, center + 1, right);
		Merge(A, tempArray, left, center + 1, right);
	}
}

void MergeSort(int *A, int n)
{
	int * tempArray = (int *)malloc(sizeof(int) * n);

	if(tempArray != NULL)
	{
		MSort(A, tempArray, 0, n - 1);
		free(tempArray);
	}
	else
	{
		printf("no enough memory!\n");
	}
}

int main()
{
	int A[] = {3, 4, 5, 7, 1, 8, 9, 2, 10, 6}; 

	printf("before sort...\n");
	PrintArrag(A, 10);;

	MergeSort(A, 10);

	printf("after sort...\n");
	PrintArrag(A, 10);

	return 0;

}