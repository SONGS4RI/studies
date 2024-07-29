#include<stdio.h>
int main()
{
    int n,num[10]={0,},i=0;
    scanf("%d",&n);
    while(n>0)
    {
        num[i]=n%10;
        n/=10;
        i++;
    }
    for(int j=0; j<i;j++)
    {
        for(int k=j+1; k<i;k++)
        {
            if(num[j]<num[k])
            {
                n = num[j];
                num[j] = num[k];
                num[k] = n;
            }
        }
    }
    for(int j=0; j<i;j++)printf("%d",num[j]);

    return 0;
}