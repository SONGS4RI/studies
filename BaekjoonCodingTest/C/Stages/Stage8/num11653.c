#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    if(n==1) exit(0);
    while(1)
    {
        for(int i = 2; i<=n;i++)
        {
            if((n/i)*i==n)
            {
                printf("%d\n",i);
                n = n/i;
                break;
            }
            
        }
        if(n==1) break;
    }
    return 0;
}
