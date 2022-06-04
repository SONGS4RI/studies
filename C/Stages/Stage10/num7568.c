#include<stdio.h>

int main()
{
    int n,x[50]={0,},y[50]={0,};
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d %d",&x[i],&y[i]);       
    }
    for(int i=0; i<n; i++)
    {
        int cnt =0;
        for(int j=0;j<n;j++)
        {
            if(x[i]<x[j]&&y[i]<y[j]) cnt++;
        }
        printf("%d ",cnt+1);
    }

    return 0;
}