#include<iostream>
using namespace std;

void ReplaceBlank(char *str, int length)
{
	char *p = str;
	int numberOfBlank = 0;
	int originLength = 0;

	if(str == NULL || length <= 0)
		return;
	while(*p)
	{	
		++originLength;
		if(*p == ' ')
			++numberOfBlank;
		++p;
	}

	int newLength = originLength + 2 * numberOfBlank;

	if(newLength > length)
		return;

	while(originLength >= 0)
	{
		if(str[originLength] == ' ')
		{
			str[newLength--] = '0';
			str[newLength--] = '2';
			str[newLength--] = '%';
		}
		else
			str[newLength--] = str[originLength];

		--originLength;
	}

}
