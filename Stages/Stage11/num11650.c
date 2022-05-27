#include<stdio.h>
int main()
{
    int n,dot[200001][200001]={0,},x,y;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d %d",&x,&y);
        dot[x][y] = 1;
    }
    

    return 0;
}