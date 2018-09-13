#include<stdio.h>

int InputTestCase()
{
	int TestCase; //0 - 255 %c 1byte
	printf("Enter TestCase Within '1 - 200': ");
	scanf("%d",&TestCase);
	if(TestCase<1 || TestCase >200)
	{
		printf("error input\n TestCase will Go with number:'1'\n");
		TestCase = 1;
	}
	return TestCase;
}
int InputArrayLength()
{
	int Length; //0 - 65535 %d 2bytes
	printf("Enter Length of Array '1 - 1000': ");
	scanf("%d",&Length);
	if(Length <1|| Length >1000)
	{
		printf("error input\n Length will Go with number:'1'\n");
		Length = 1;
	}
	return Length;
}
//O(N^2)
void InsertSort(int *a, int length)
{
	int tmp;
	int i,j;
	for(i = 1; i<length; i++)
	{
		tmp = a[i];
		for(j = i; j>0&&a[j-1]>tmp;j--)
		{
			a[j]=a[j-1];
		}
		a[j] = tmp;
	}
}

int Kadane(int length,int *pArray)
{
	int is_all_negative = 1;
	int j = 0;//for position of tmp;
	int tmp[length]; 
	int subsum = 0;
	for(int i = 0; i<length; i++)
	{
		if(pArray[i] <0)
		{
			tmp[j++] = subsum;
			subsum = 0;
			//deal with all negative numbers:
			if( is_all_negative == 1 && i == length-1)
			{
				InsertSort(pArray,length);
				subsum = pArray[length-1];
				return subsum;
			}
			continue;
		}
		else
		{
			subsum = subsum + pArray[i];
			is_all_negative = 0;	
		}
		tmp[j++] = subsum;
	
	}
	InsertSort(tmp,j);
	return tmp[j-1];
}	

int main()
{
	int testcase = InputTestCase();
	int length = InputArrayLength();
	int test[length];
	int i = 0;
	while(testcase-- >0)
	{	
		printf("testcase = %d\n",testcase);
		printf("Enter serise of number: ");
		while (scanf("%d", &test[i++]) == 1 && i<length);
		printf("sum = %d\n",Kadane(length,test));
		if(testcase >0)
			length = InputArrayLength();
		
	}
	return 0;
}






