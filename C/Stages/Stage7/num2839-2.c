#include <stdio.h>

int main()
{
    int N,count=0;
    int i;
    scanf("%d",&N);

    for(i=N/5; i>=0;i--)
    {
        if((N-5*i)%3==0)
        {
            N-=5*i;
            break;
        }
    }
    if(i>=0) printf("%d",i+N/3);
    else printf("-1");
}