/* 时间复杂度最坏O(n^2) 最好O(n)
*/
#include<stdio.h>

void Swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort0(int *A, int n)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			if(A[i] > A[j])
				Swap(&A[i], &A[j]);
		}
	}
}

void BubbleSort1(int *A, int n)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = n - 1; j >= i; j--)
		{
			if(A[j] < A[j - 1])
				Swap(&A[j], &A[j - 1]);
		}
	}
}

void BubbleSort2(int *A, int n)
{
	int i, j;
	int flag = 1;
	for(i = 0; i < n && flag; i++)
	{
		flag = 0;
		for(j = n - 1; j >= i; j--)
		{
			if(A[j] < A[j - 1])
			{
				Swap(&A[j], &A[j - 1]);
				flag = 1;
			}
		}
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
	PrintArrag(A, 10);

//	BubbleSort0(A, 10);
//	BubbleSort1(A, 10);
	BubbleSort2(A, 10);

	printf("after sort...\n");
	PrintArrag(A, 10);

	return 0;
}