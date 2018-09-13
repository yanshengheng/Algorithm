#include<stdio.h>

int MissingNumber(int *pArray, int length)
{
	int missing_number = -1;
	for(int i = 0; i<length; i++)
	{
		if(i+1 < length &&pArray[i+1] - pArray[i] == 2)
			missing_number = pArray[i]+1;
	}
	return missing_number;
}
int main()
{
	int testcase;
	int length;
	scanf("%d",&testcase);
	scanf("%d",&length);
	int A[length-1];
	int i = 0;
	while(testcase-- >0)
	{
		while(scanf("%d",&A[i++]) == 1&&i < length-1);
		printf("the Missing number: %d\n",MissingNumber(A,length-1));
		if(testcase > 0)
		{
			scanf("%d",&length);
			i = 0;
		}
	}
	return 0;
}
