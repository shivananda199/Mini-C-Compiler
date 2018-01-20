#include<stdio.h>
int main()
{
    int a,i,flag=0;
    printf("Input no");
    scanf("%d",&a);
    i=2;
    while(i <= a/2)
    {
        if(a%i == 0)
        {
            flag=1;
            break;
        }
        i++;
    }
    if(flag==0)
        printf("Prime");
    else
        printf("Not Prime");
    return 0;
}
