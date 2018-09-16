#include<stdio.h>
#include<stdlib.h>
#include"Integer/List.h"

//we aim to create a arraylist like java.
int main()
{
	//declear a list by do this:
	/*struct Node
	{
		int Element;
		struct Node *Next;
	};//here we create memory spaces;
	*/
	struct Node *MyList;//we use pointer to operate it;
	struct Node *Head;//to set the first position of the list 
	//1.we shall allocate a memory spaces for our list;
	MyList = (struct Node*)malloc(sizeof(struct Node));//image there is a box that put in address:Mylist 
	Head = MyList;
	//this box now has something;
	MyList->Element = 1;
	MyList->Next = 0;
	printf("this is first Element:%d\n",MyList->Element);

	//using Insert Operation
	Insert(2,MyList,Head);
	printf("this is the second Element: %d\n",MyList->Next->Element);
	return 0;
}
