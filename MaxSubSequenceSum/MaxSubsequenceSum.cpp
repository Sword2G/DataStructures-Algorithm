#include<stdio.h>
// O(n^2)
int MaxSubSequenceSum1(const int *A, int N)
{	
	int i, j, thisSum, maxSum = 0;
	for(i = 0; i < N; i++)
	{
		thisSum = 0;
		for(j = i; j < N; j++)
		{
			thisSum += A[j];
			if(thisSum > maxSum)
				maxSum = thisSum;
		}
	}

	return maxSum;
}

//////////////////////////////////////////////////////////////////////////
//  O(N * logN)
int Max3(int a, int b, int c)
{
	int max;

	max = a > b?a:b;
	if(c > max)
		max = c;
	return max;
}

int MaxSub(const int *A, int left, int right)
{
	int i, center;
	int leftMax, rightMax;
	int leftBorderSum, rightBorderSum;
	int leftBorderMax, rightBorderMax;
	center = (left + right) / 2;

	if(left == right)
	{
		if(A[left] > 0)
			return A[left];
		else
			return 0;
	}

	leftMax = MaxSub(A, left, center);
	rightMax = MaxSub(A, center + 1, right);

	leftBorderSum = 0;
	leftBorderMax = 0;
	for(i = center; i >= left; i--)
	{
		leftBorderSum += A[i];
		if(leftBorderSum > leftBorderMax)
			leftBorderMax = leftBorderSum;
	}

	rightBorderSum = 0;
	rightBorderMax = 0;
	for(i = center + 1; i <= right; i++)
	{
		rightBorderSum += A[i];
		if(rightBorderSum > rightBorderMax)
			rightBorderMax = rightBorderSum;
	}

	return Max3(leftMax, rightMax, leftBorderMax + rightBorderMax);

}

int MaxSubSequenceSum2(const int *A, int N)
{	
	return MaxSub(A, 0, N - 1);
}

//////////////////////////////////////////////////////////////////////////
// O(N)
int MaxSubSequenceSum3(const int *A, int N)
{	
	int i, maxSum, thisSum;
	thisSum = maxSum = 0;
	for(i = 0; i < N; i++)
	{
		thisSum += A[i];

		if(thisSum > maxSum)
			maxSum = thisSum;
		else if(thisSum < 0)
			thisSum = 0;
	}
	
	return maxSum;
}


int main()
{
	int A[8] = {4, -3, 5, -2, -1, 2, 6, -2};
	int max1 = 0, max2 = 0, max3 = 0;
	max1 = MaxSubSequenceSum1(A, 8);
	max2 = MaxSubSequenceSum2(A, 8);
	max3 = MaxSubSequenceSum3(A, 8);
	
	printf("MaxSubSequenceSum1(A, 8) ====> %d\n",max1);
	printf("MaxSubSequenceSum2(A, 8) ====> %d\n",max2);
	printf("MaxSubSequenceSum3(A, 8) ====> %d\n",max3);

	return 0;
}

