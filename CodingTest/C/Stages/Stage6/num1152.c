#include<stdio.h>
int main()
{
    char s1[1000000]={0,};
    int i = 0, cnt = 0;

    while(1)
    {
        while(1)
            {
                scanf("%c",&s1[i]);
                if(s1[i]==' ' || s1[i]=='\n') break;
                i++;
            }
        if(i!=0)cnt ++;
        if(s1[i-1]==' ') cnt--;
        if(s1[i]=='\n') break;
        i++;      
    }
    printf("%d",cnt);

    return 0;
}