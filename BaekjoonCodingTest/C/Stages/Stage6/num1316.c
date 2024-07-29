#include<stdio.h>
int main()
{
    int n,cnt=0;
    char arr[100] = {0,};
    scanf("%d",&n);
    for(int i = 0; i<n; i++)
    {
        int j = 0;
        scanf("%s",&arr);
        while(arr[j]!=0)
        {
            int k = j+1,con=0;
            
            while (arr[k]!=0)
            {
                if(arr[k]==arr[k-1]) con++;
                else con=0;
                if(arr[j]==arr[k] && con==0)
                {
                    cnt--;
                    break;
                }
                k++;
            }
            if(arr[j]==arr[k] && k-j!=1) break;
            j++;
        }
        cnt++;
    }
    printf("%d",cnt);

    return 0;
}