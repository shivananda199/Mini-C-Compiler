#include<stdio.h>
int foo(int a)
{
	float s;
	return s;	//return type mismatch
}
int sum(int b,int c)
{
	int s;
	s=b+c;
	return s;
}
void main()
{
	int p=3;
	int q=4;
	float f=4.5;
	int d;
	d=sum(p,f);	//parameter type mismatch
	return;
}
