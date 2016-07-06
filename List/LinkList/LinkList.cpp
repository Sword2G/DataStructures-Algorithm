//////////////////////////////////////////////////////////////////////////
/*如果涉及到插入到第i个前面，删除，P要指向待查找的前面一个，因此p初始化为*L ，j初始化为1,并判断p->next是否为NULL,否则p初始化为(*L)->next
链表的简单应用：
1 一元多项式的加减乘除
2 基数排序
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int ElementType;

struct Node{
	ElementType data;
	struct Node * next;
};

typedef struct Node * LinkList;
typedef struct Node * ptrNode;

void InitListHead(LinkList *L, int n);
void InitListTail(LinkList *L, int n);
int ListEmpty(LinkList L);
int GetElem(LinkList L, int i, ElementType *e );
ptrNode Find(LinkList L, ElementType X);
ptrNode FindPrevious(LinkList L, ElementType X);
int ListInsert(LinkList *L, int i, ElementType e);
void ListDelete1(LinkList *L, ElementType X);
int ListDelete2(LinkList *L, int i, ElementType *e);
int ListLength(LinkList L);
void ClearList(LinkList *L);
void printLinkList(LinkList L);


void InitListHead(LinkList *L, int n)
{
	struct Node *p;
	srand(time(0));
	int i;
	*L = (struct Node *)malloc(sizeof(struct Node));
	(*L)->next = NULL;
	for(i = 0; i < n; i++)
	{
		p = (ptrNode)malloc(sizeof(struct Node));
		p->data = rand()%100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}	
}

void InitListTail(LinkList *L, int n)
{
	struct Node *p;
	struct Node * rear;

	srand(time(0));
	int i;
	*L = (struct Node *)malloc(sizeof(struct Node));
	rear = *L;

	for(i = 0; i < n; i++)
	{
		p = (struct Node *)malloc(sizeof(struct Node));
		p->data = rand()%100 + 1;
		rear->next = p;
		rear = p;
	}

	rear->next = NULL;
}

int ListEmpty(LinkList L)
{
	return (L->next == NULL);
}

int IsLast(LinkList L, ptrNode p)
{
	return p->next == NULL;
}

int GetElem(LinkList L, int i, ElementType *e )
{
	ptrNode p = L->next;
	int j = 1;
	while(p && j < i)
	{
		p = p->next;
		j++;
	}
	if(!p || j > i)
	{
		return 0;
	}

	*e = p->data;
	return 1;
}

ptrNode Find(LinkList L, ElementType X)
{
	ptrNode p = L->next;
	while(p && X != p->data)
		p = p->next;
	return p;
}

ptrNode FindPrevious(LinkList L, ElementType X)
{
	ptrNode p = L;

	while(p->next && X != p->next->data)
		p = p->next;

	return p;
}

//insert behind i
int ListInsert(LinkList *L, int i, ElementType X)
{
	ptrNode p = (*L)->next;
	int j = 1;

	while(p && j < i)
	{
		p = p->next;
		j++;
	}
	if(!p || j > i)
		return 0;
	
	ptrNode s = (ptrNode)malloc(sizeof(Node));
	s->data = X;
	s->next = p->next;
	p->next =s;

	return 1;
}

void ListDelete1(LinkList *L, ElementType X)
{
	ptrNode p = FindPrevious(*L, X);

	if(!IsLast(*L, p))
	{
		ptrNode temp = p->next;
		p->next = temp->next;
		free(temp);
	}
}

int ListDelete2(LinkList *L, int i, ElementType *e)
{
	ptrNode p = *L, temp;
	int j = 1;

	while(p->next && j < i)
	{
		p = p->next;
		j++;
	}

	if(!(p->next) || j > i)
		return 0;

	temp = p->next;
	p->next = temp->next;
	free (temp);

	return 1;
}

int ListLength(LinkList L)
{
	ptrNode p = L;
	int len = 0;

	while(p)
	{
		p = p->next;
		len++;
	}

	return len;
}

void ClearList(LinkList *L)
{
	ptrNode p = (*L)->next, temp;
	(*L)->next = NULL;
	while(p)
	{
		temp = p->next;
		free(p);
		p = temp;
	}
}

void printLinkList(LinkList L)
{
	ptrNode p = L->next;
	if(p == NULL)
	{
		printf("No data in LinkList\n");
	}
	else
	{
		while(p)
		{
			printf("%d ",p->data);
			p = p->next;
		}
	}	
	printf("\n");
}

int main()
{
	LinkList L;
	int n = 10;
	InitListHead(&L, n);
	InitListTail(&L, n);
	printf("ListEmpty(L) = %d\n", ListEmpty(L));

	int index = 5;
	int e;
	GetElem(L, index, &e);
	printf("Get %d at index %d\n", e, index);
	printLinkList(L);

	ListInsert(&L, index, e);
	printf("Insert %d at index %d\n", e, index);
	printLinkList(L);

	ListDelete2(&L, index, &e);
	printf("Delete %d at index %d\n", e, index);
	printLinkList(L);

	printf("ListLength(L) = %d\n", ListLength(L));

	ClearList(&L);
	printLinkList(L);

	return 0;
}