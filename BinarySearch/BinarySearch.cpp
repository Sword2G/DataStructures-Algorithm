#include<stdio.h>

int BinarySearch(const int *A, int X, int N)
{
	int low, high, mid;

	low = 0;
	high = N - 1;
	while(low <= high)
	{
		mid = (low + high) / 2;
			
		if(X > A[mid])
		{
			low = mid + 1;
		}
		else if(X < A[mid])
		{
			high = mid - 1;
		}
		else
			return mid;
	}

	return -1;
}


int main()
{
	int A[] = {1, 2, 3, 4, 5, 6};
	int pos, x = 4;
	pos = BinarySearch(A, x, 6);
	if(pos == -1)
		printf("NOT FOUND\n");

	printf("find %d at %d\n", x, pos);

	return 0;
}