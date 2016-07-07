/*
对于一个数组 奇数在前，偶数在后，保证稳定性
1 快排思想，不能保证稳定性
2 插入思想，遇到奇数往前查找，找到第一个奇数，插在其后面
*/
void reOrderArray(vector<int> &array) 
{

    int i, j, temp;
    int length = array.size();
        
    for(i = 1;i < length; i++)
    {
        if(array[i] % 2 == 1)
        {
            temp = array[i];
                
            for(j = i;j > 0 && array[j-1] % 2 == 0; j--)
            {
                array[j] = array[j - 1];
            }
                
            array[j] = temp;
    	}
    }
}