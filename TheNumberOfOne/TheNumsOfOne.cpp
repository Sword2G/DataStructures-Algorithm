#include<stdio.h>

//һ������ȥ 1 ��������� & �ǰ���������ұߵ� 1 ��� 0
int numberOfOne0(unsigned int n)
{
	int counts = 0;

	while(n)
	{
		n = n & (n - 1);
		counts++;
	}

	return counts;
}

// ʮ����ת���ɶ����ƣ�Ȼ���� 1 �ĸ���
int numberOfOne1(unsigned int n)
{
	int counts = 0;

	while(n)
	{
		if(n % 2 == 1)
			counts++;
		n /= 2;
	}

	return counts;
}

//ÿ�μ�����һλ
int numberOfOne2(unsigned int n)
{
	int counts = 0;

	while(n)
	{
		if((n & 1) == 1)
			counts++;
		n >>= 1;
	}

	return counts;
}

// �� n д�ɶ�������ʽ��Ȼ������λʮ������ӣ��ظ�������̣�ֱ��ֻʣ��һλ,���� 10 = 1010��1 + 0 = 1 �� 1 + 0 = 1�� 1 + 1 = 2,���� 2 �� 1
int numberOfOne3(unsigned int n) 
{ 
    n = (n &0x55555555) + ((n >>1) &0x55555555) ; 
    n = (n &0x33333333) + ((n >>2) &0x33333333) ; 
    n = (n &0x0f0f0f0f) + ((n >>4) &0x0f0f0f0f) ; 
    n = (n &0x00ff00ff) + ((n >>8) &0x00ff00ff) ; 
    n = (n &0x0000ffff) + ((n >>16) &0x0000ffff) ; 

    return n ; 
}


int numberOfOne(int n)
{
	int counts = 0;
	// �����������λ��� 1 �ڽ������²���
	if(n < 0)
	{
		n &= 0x7fffffff;
		counts++;
	}
	while(n)
	{
		if( n % 2 == 1)
			counts++;
		n /= 2;
	}

	return counts;
}

struct _byte 
{ 
    unsigned a:1; 
    unsigned b:1; 
    unsigned c:1; 
    unsigned d:1; 
    unsigned e:1; 
    unsigned f:1; 
    unsigned g:1; 
    unsigned h:1; 
}; 

long numberOfOne( unsigned char b ) 
{
    struct _byte *by = (struct _byte*)&b; 
    return (by->a+by->b+by->c+by->d+by->e+by->f+by->g+by->h); 
}


int main()
{
	unsigned int n = 217;

	printf("%d\n", numberOfOne0(n));
	printf("%d\n", numberOfOne1(n));
	printf("%d\n", numberOfOne2(n));
	printf("%d\n", numberOfOne3(n));

}

