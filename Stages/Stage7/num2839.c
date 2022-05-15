#include<stdio.h>
int main()
{
    int n, sum=0,a=0,b=0;
    scanf("%d",&n);
    if (n%5 == 1) printf("%d",n/5+1);
    else if(n%5 ==2)
    {
        if(n==7) printf("%d",-1);
        else printf("%d",n/5+2);
    }
    else if(n%5 ==3) printf("%d",n/5+1);
    else if(n%5 ==4) 
    {
        if(n==4) printf("%d",-1);
        else printf("%d",n/5+2);
    }
    else printf("%d",n/5);

    return 0;
}