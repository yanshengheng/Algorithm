#include"List.h"
#include<stdlib.h>
/*
	self-define type name:
	struct Node
	{
		int *Element;
		struct Node *Next;
	};
	typedef struct Node *PtrToNode;
	typedef PtrToNode List,Position;
*/

int IsEmpty(List L)
{
	return L->Next == 0;//0 to replace with NULL
}

int IsLast(Position P, List L)//'Position' 'List' are 'Struct Node *'
{
	return P->Next == 0;
}

Position Find(int X, List L)
{
	Position P;
	P = L->Next;//if there are only only Element,no need to 'while'
	while(P != NULL && P->Element != X)
	{
		P = P->Next;
	}
	return P;
}
Position FindPrevious(int X, List L)
{
	Position P = L;
	while(P->Next != 0 && P->Next->Element != X)
	{
		P = P->Next;
	}
	return P;
}
//This is mainly how list create
void Insert(int X,List L, Position P)
{
	Position TmpCell;
	TmpCell = malloc(sizeof(struct Node));//<stdlib.h>
	if(TmpCell == 0)
	{
		//perror("Out of Space !!!");
		exit(0);
	}
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}
void Delete(int X, List L)
{
	Position P, TmpCell;
	P = FindPrevious(X,L);
	if(!IsLast(P,L))
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}
void DeleteList(List L)
{
	Position P, Tmp;
	P = L->Next;
	L->Next = 0;
	while(P !=0)
	{
		Tmp = P->Next;
		free(P);
		P = Tmp;
	}
}
