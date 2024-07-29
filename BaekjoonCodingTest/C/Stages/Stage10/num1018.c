#include<stdio.h>

int main()
{
    int n,m,min=0,res=64;
    char arr[50][50]={0,};
    scanf("%d %d",&n,&m);
    for(int i=0; i<n;i++) scanf("%s",&arr[i]);
    
    for(int i=0; i<n-7;i++)
    {
        for(int j=0; j<m-7;j++)
        {
            for(int k=i; k<i+8; k++)
            {
                int cnt = 0;
                for(int l=j; l<j+8; l++)
                {
                    if((k+l)%2==0 && arr[k][l]!=arr[i][j] ) cnt++;
                    if((k+l)%2==1 && arr[k][l]==arr[i][j] ) cnt++;
                }
                min += cnt;
            }
            if(min>=32) min = 64-min;
            if(min<res) res = min;
            min = 0;
        }
    }
    printf("%d",res);

    return 0;
}