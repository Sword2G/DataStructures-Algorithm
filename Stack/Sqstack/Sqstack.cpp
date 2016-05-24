#include<stdio.h>
#include<stdlib.h>

typedef int ElementType; 

typedef struct SatcRecord{
	int capacity;
	int top;
	ElementType *data;
} StackRecord;

typedef StackRecord* Sqstack;

Sqstack initStack(int MaxSize)
{
	Sqstack s;
	s = (Sqstack)malloc(sizeof(StackRecord));
	if(s == NULL)
		printf("Out of Memory!\n");
	s->capacity = MaxSize;
	s->top = -1;
	s->data = (ElementType *)malloc(sizeof(ElementType) * s->capacity);
	if(s->data == NULL)
		printf("Out of memory!\n");

	return s;
}

void destoryStack(Sqstack s)
{
	if(s != NULL)
	{
		free(s->data);
		free(s);
	}
}

int isEmpty(Sqstack s)
{
	return s->top == -1;
}

int isFull(Sqstack s)
{
	return s->top == s->capacity - 1;
}

int Push(Sqstack s, ElementType e)
{
	if(isFull(s))
		return -1;
	else
		s->data[++s->top] = e;
	return 0;
}

ElementType Pop(Sqstack s)
{
	if(isEmpty(s))
		return -1;//Error(maybe not reasonable)
	else
		return s->data[s->top--];
} 

ElementType Top(Sqstack s)
{
	if(isEmpty(s))
		return -1;
	else
		return s->data[s->top];
}


int main()
{
	Sqstack s;
	int i = 0;
	s = initStack(10);
	for(; i < 10; i++)
		Push(s, i);
	for(i = 0; i < 10; i++)
		printf("%d ",Pop(s));
	printf("\n");

	return 0;
}
