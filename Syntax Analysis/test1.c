//without error - nested if-else
#include<stdio.h>
#define x 3
int main()
{
	int a=4;
	if(a<10)
	{
		a = a + 1;
		printf("\n%d\n",a);
	}
	else if(a<5)
	{
		a = a + 2;
	}
	else
	{
		a = a - 2;
	}
	return 0;
}
