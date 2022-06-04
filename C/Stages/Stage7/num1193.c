#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,x,res_a=0;
    scanf("%d",&x);
    if(x==1)
    {
        printf("1/1");
        exit(0);
    }
    for(int i=1; ;i++)
    {
        res_a = res_a + i;
        if( x<=res_a && x!=1)
        {
            a = i-(res_a-x);
            b = res_a-x+1;
            if(i%2==0) printf("%d/%d",a,b);
            else printf("%d/%d",b,a);
            break;
        }
    }
    return 0;
}
