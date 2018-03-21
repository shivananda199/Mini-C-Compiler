#include <stdio.h>
int main()
{
	int a = 5.4;	//type mismatch
	int b=67;
	float f=6.7;
	b=f;		//type mismatch (int = float)
	return 0;
}
