#include <stdio.h>
int main()
{
	int a=4;
	int b=5;
	{
		int d=56;
	}
	int sum;
	sum=a+b;
	{
		int d=20;
	}
	foo();
	d=89;		//variable 'd' out of scope
}
