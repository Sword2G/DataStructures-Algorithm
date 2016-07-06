#include<stdio.h>

//一个数减去 1 再与这个数 & 是把这个数最右边的 1 变成 0
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

// 十进制转化成二进制，然后数 1 的个数
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

//每次检查最后一位
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

// 将 n 写成二进制形式，然后相邻位十进制相加，重复这个过程，直到只剩下一位,比如 10 = 1010，1 + 0 = 1 ， 1 + 0 = 1， 1 + 1 = 2,共有 2 个 1
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
	// 将负数的最高位变成 1 在进行如下操作
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

