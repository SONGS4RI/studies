#include<stdio.h>
int main()
{
    int n,arr[10001]={0,},num;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num);
        arr[num]++;
    }
    for(int i=1;i<10001;i++)
    {
        if(arr[i]!=0)
        {
            for(int j=0; j<arr[i]; j++) printf("%d\n",i);
        }
    }    
    return 0;
}
// 카운트 정렬계수 방법이다.