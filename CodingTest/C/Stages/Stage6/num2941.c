#include<stdio.h>
int main()
{
    char arr[102] ={0,};
    int i =0,cnt=0;
    scanf("%s",&arr);
    while(arr[i]!=0)
    {
        if(arr[i]=='c' && (arr[i+1]=='='||arr[i+1]=='-')) cnt--;
        else if(arr[i]=='d' && arr[i+1]=='z' &&arr[i+2]=='=') cnt = cnt-2;
        else if(arr[i]=='d' && arr[i+1]=='-') cnt --;
        else if(arr[i]=='l' && arr[i+1]=='j') cnt --;
        else if(arr[i]=='n' && arr[i+1]=='j') cnt --;
        else if(arr[i]=='s' && arr[i+1]=='=') cnt --;
        else if(arr[i]=='z' && arr[i+1]=='=' && arr[i-1]!='d') cnt --;
        cnt++;
        i++;
    }
    printf("%d",cnt);
    
    return 0;
}