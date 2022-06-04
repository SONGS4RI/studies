#include<stdio.h>
int main()
{
    int t, k, n, res_a[14]={0,},res_b[14]={0,};
    scanf("%d",&t);
    
    for(int i = 0; i<t; i++)
    {
        scanf("%d\n%d",&k,&n);
        for(int j=0; j<n; j++) res_a[j] = j+1;
        for(int l=1; l<=k;l++)
        {
            for(int j=0; j<n; j++)
            {
                if( j == 0) res_b[j] = 1;
                else
                {
                    res_b[j] = res_b[j-1]+res_a[j];
                    res_a[j] = res_b[j];
                }

            }
        }
        printf("%d\n",res_b[n-1]); 
    }
    return 0;
}