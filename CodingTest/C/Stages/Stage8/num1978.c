#include<stdio.h>
int main()
{
    int n,cnt=0,input;
    scanf("%d",&n);
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&input);
        int j =2;
        if(input == 1 ) cnt--;
        while(j<input)
        {
            if((input/j)*j==input && j!=input) 
            {
                cnt--;
                break;
            }
            else j++;
        }
        cnt++;
    }
    printf("%d",cnt);
    return 0;
}
