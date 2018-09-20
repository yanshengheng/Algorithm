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
	MyList = CreateList();
	printf("the first Element: %d\n",GetElement(MyList,0));
	
	Append(MyList,1);
	//printf("start the third Append: \n");
	Append(MyList,2);
	Append(MyList,3);
	//printf("the second Element: %d\n",GetElement(MyList,1));
	printf("the third Element: %d\n",GetElement(MyList,2));
	printf("the fourth Element: %d\n",GetElement(MyList,3));
	//printf("the first Element: %d\n", GetElement(MyList,0));
	return 0;
}
