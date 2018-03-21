#include <stdio.h>
void main()
{
	int a[0];	//array index error (has to be greater than zero)
	int b[8.5];	//array index cannot be a float value
	int c=5;
	float d;
        int i;
        int c=3;	//redeclaration of variable 'c'
        int sum;
        sum=0;

	for(i=0;i<12;i++)
	{
		sum=sum+i;
	}
	return;
}
