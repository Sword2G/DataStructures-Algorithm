/*
栈的应用：
1 函数调用 
2 逆波兰式&四则混合运算
*/
#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;
typedef struct Node{
	ElementType data;
	struct Node * next;
} StackNode;


typedef struct LinkStack{
	StackNode* top;
	int count;
} LinkStack;

void initStack(LinkStack *s)
{
	s->top = NULL;
	s->count = 0;
// 	s->count = 0;
// 	s->top = (StackNode *)malloc(sizeof(StackNode));
// 	if(s->top == NULL)
// 		printf("Out of memory!\n");
// 
// 	s->top->next = NULL;
}

void destoryStack(LinkStack *s)
{
	StackNode *p = s->top;
	s->top = NULL;
	s->count = 0;
	StackNode *temp;
	while(p)
	{
		temp = p->next;
		free(p);
		p = temp;
	}
}

int isEmpty(LinkStack *s)
{
	return s->top == NULL;
}


int Push(LinkStack *s, ElementType e)
{
	StackNode *ss = (StackNode *)malloc(sizeof(StackNode));
	if(ss == NULL)
		return -1;

	ss->data = e;
	if(s->count == 0)
	{		
		ss->next = NULL;
		s->top = ss;
	}
	else
	{
		ss->next = s->top;
		s->top = ss;		
	}

	s->count++;
	
	return 0;
}

ElementType Pop(LinkStack *s)
{
	StackNode * ss;
	ElementType e;
	if(isEmpty(s))
		return -1;//Error(maybe not reasonable)
	else
	{
		ss = s->top;
		e = ss->data;
		s->top = ss->next;
		free(ss);
		s->count--;
	}

	return e;
} 

int Top(LinkStack *s)
{
	if(isEmpty(s))
		return -1;
	else
		return s->top->data;
}


int main()
{
	LinkStack s;
	int i = 0;
	initStack(&s);
	//s = initStack2();
	
	for(; i < 10; i++)
		Push(&s, i);
	
	printf("isEmpty(&s) = %d\n",isEmpty(&s));

	for(i = 0; i < 10; i++)
		printf("%d ",Pop(&s));

	printf("\n");

	for(; i < 10; i++)
		Push(&s, i);

	destoryStack(&s);
	printf("isEmpty(&s) = %d\n",isEmpty(&s));
	
	return 0;
}


