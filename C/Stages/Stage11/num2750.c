#include<stdio.h>
int main()
{
    int n, arr[1000],num;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    for(int j=0;j<n;j++)
    {
        for(int k=j+1;k<n;k++)
        {
            if(arr[j]>arr[k])
            {
                num = arr[j];
                arr[j] = arr[k];
                arr[k] = num;
            }
        }
    }

    for(int i=0;i<n;i++) printf("%d\n",arr[i]);
    return 0;
}