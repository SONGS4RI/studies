#include<stdio.h>
int main()
{
    int n,res=1;
    scanf("%d",&n);
    for(int i =0; ;i++)
    {
        res += 6*i;
        if(n<=res)
        {
            printf("%d",i+1);
            break;
        }
    }

    return 0;
}
