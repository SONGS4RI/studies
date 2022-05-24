#include<stdio.h>
int main()
{
    int n,k,l=0,arr[10]={0,},index[10000];
    scanf("%d",&n);

    for(int i=666; l<10000 ;i++)
    {
        k = i;
        int m =0;
        while(k>0)
        {
            arr[m] = k%10;
            k/=10;
            m++;
        }
        for(int j=0;arr[j+2]!=0;j++)
        {
            if(arr[j]==arr[j+1] && arr[j+1]==arr[j+2] && arr[j]==6)
            {
                index[l]=i;
                l++;
                break;
            }
        }
    }
    printf("%d",index[n-1]);

    return 0;
}