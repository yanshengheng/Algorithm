/*gcc version:
 *Apple LLVM version 10.0.0 (clang-1000.10.44.2)
 */

#include"List.h"
#include<stdlib.h>
#include<stdio.h>
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
/* aim to design a convient list operation */

struct Node *CreateList()
{
	struct Node *list = (struct Node*)malloc(sizeof(struct Node));
	if(list == 0)
    {
        printf("Out of Space !!!");
        exit(0);
    }
	list->Element = 0;
	list->Next = 0;
	return list;
}

int isEmpty(List L )
{
	if(L==0)
	{
		printf("Empty List");
		return 1;
	}
	return 0;
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
{}

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

int GetElement(List L, int p)
{
	Position P;
	if(isEmpty(L))
	{
		exit(0);
	}
	if(p == 0)
	{
		return L->Element;
	}
	else
	{
		P = L;
		for(int i = 0; i < p; i++)
		{
			if(P == 0)
			{
				printf("Out of Index\n");
				exit(0);
			}
			P = P ->Next;
		}
		return P->Element;
	}
}
void Append(List L,int Elmt)//Elm:Element
{
	Position P;
	List tmp;
	List cell = CreateList();
	cell->Element = Elmt;
	if(isEmpty(L))
		exit(0);
		
	P = L;
	while(P != 0)
	{	
		if(P->Next == 0)
		{
			P->Next = cell;
			break;
		}
		else
		{
			P = P->Next;
			if(isEmpty(L))
				exit(1);
			
		}

	}
}

