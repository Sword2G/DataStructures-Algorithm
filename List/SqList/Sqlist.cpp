#include<stdio.h>
#define MAXSIZE 20

typedef int ElementType;

struct SqList{
	ElementType data[MAXSIZE];
	int length;
};

void InitList(SqList *L);
int ListEmpty(SqList L);
void ClearList(SqList *L);
int GetElem(SqList L, int i, ElementType *e );
int Locate(SqList L, ElementType e);
int ListInsert(SqList *L, int i, ElementType e);
int ListDelete(SqList *L, int i, ElementType *e);
int ListLength(SqList L);
void printSqList(SqList L);


void InitList(SqList *L)
{
	int i;
	for(i = 0; i < 10; i++)
	{
		L->data[i] = i;
	}

	L->length = 10;
}

int ListEmpty(SqList L)
{
	return L.length == 0;
}

void ClearList(SqList *L)
{
	L->length = 0;
}

int GetElem(SqList L, int i, ElementType *e )
{
	if(L.length == 0 || i < 0 || i > L.length)
		return 0;
	else
	{
		*e = L.data[i - 1];
		return 1;
	}
}

int Locate(SqList L, ElementType e)
{
	int i;
	for(i = 0; i < L.length; i++)
		if(e == L.data[i])
			return (i+1);
	return 0;
}

int ListInsert(SqList *L, int i, ElementType e)
{
	int k;

	if(L->length == MAXSIZE || i < 1 || i > L->length)
		return 0;

	for(k = L->length - 1; k >= i - 1; k--)
		L->data[k + 1] = L->data[k];

	L->data[i - 1] = e;

	L->length++;

	return 1;

}

int ListDelete(SqList *L, int i, ElementType *e)
{
	int k;
	if(L->length == 0 || i < 1 || i > L->length)
		return 0;

	*e = L->data[i - 1]; 

	for(k = i-1; k <= L->length-1; k++)
		L->data[k] = L->data[k+1];

	L->length--;

	return 1;

}

int ListLength(SqList L)
{
	return L.length;
}

void printSqList(SqList L)
{
	if(L.length == 0)
		printf("No data in SqlList\n");
	int i;
	for(i = 0; i <= L.length - 1; i++)
		printf("%d ", L.data[i]);
	printf("\n");
}


int main()
{
	struct SqList L;
	InitList(&L);
	printf("ListEmpty(L) = %d\n", ListEmpty(L));
	printSqList(L);
	
	int e;
	int index = 7;
	GetElem(L, index, &e);
	printf("the %d th number is e : %d\n", index, e);
	printf("Find %d at index %d\n", e, Locate(L, e));


	int insertNum = 100;
	ListInsert(&L, index, 100);
	printf("Insert %d at index %d  into SqList\n", insertNum, index);
	printSqList(L);

	ListDelete(&L, index, &e); 
	printf("Delete %d at index %d from SqlList\n", e, index);
	printSqList(L);
	
	printf("ListLength(L) = %d\n", ListLength(L));

    ClearList(&L);
	printf("ListEmpty(L) = %d\n", ListEmpty(L));
	printSqList(L);

	return 0;
}





