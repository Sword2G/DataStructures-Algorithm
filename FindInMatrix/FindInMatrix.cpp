#include<iostream>
using namespace std;

// 每一行进行二分查找
bool Find(vector<vector<int> > array,int target)
{
	int i;
	int rows = array.size();
	int cols = array[0].size();

	int low = 0
	int high = rows - 1;
	int center;

	for(i = 0; i < rows; i++)
	{
		
		while(low <= high)
		{
			center = (low + high) / 2;

			if(array[i][center] == target)
				return true;
			else if(array[i][center] < target)
				high = center + 1;
			else
				high = center - 1;
		}
	}

	return false;
}

bool Find(vector<vector<int> > array,int target)
{

	int rows = array.size();
	int cols = array[0].size();
		
	int row = 0;
	int col = cols - 1;

	while(row < rows && col >= 0)
	{
		if(array[row][col] == target)
			return true;
		else if(array[row][col] < target)
			row++;
		else
			col--;
	}

	return false;
}