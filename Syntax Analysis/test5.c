//with error - dangling else problem
#include<stdio.h>
#define x 3
int main()
{
	int a=4;
	if(a<10)
		printf("10");
	else
	{
		if(a<12)
			printf("11");
		else
			printf("All");
		else
			printf("error");
	}
}
