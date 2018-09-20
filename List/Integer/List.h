/*
 *Standard c does not provide any data structures;
 */
#ifndef LIST_H
#define LIST_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;


struct Node *CreateList();
//Function Declearation:
//Every Function is here, must first implicate struct Node first
List MakeEmpty(List L);

int IsEmpty(List L);
int IsLast(Position P, List L);
int GetElement(List L, int p);

Position Find(int X, List L);
Position FindPrevious(int X, List L);
Position Header(List L);
Position First(List L);
Position Advance(List L);


void Append(List L,int Elmt);
void Delete(int X, List L);
void Insert(int X, List L, Position P);
void DeleteList(List L);
#endif
//declear a List by Doing below:
struct Node
{
	int Element;
	struct Node *Next;
}MyListName;

