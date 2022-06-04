#include<stdio.h>
#include <stdlib.h>
int main()
{
    char a1[7]={0,};
    int b1[7], res1, res2,cnt=0;
    for(int i=0; i<7; i++)
    {
        scanf("%c",&a1[i]);
        b1[6-i] = a1[i]-'0';
    }
    res1 = b1[0]*100+b1[1]*10+b1[2];
    res2 = b1[4]*100+b1[5]*10+b1[6];
    for(int i=0; i<7; i++)
    {
        if(b1[i]==0) cnt++;
    }
    if(res1 == res2 || cnt!=0) exit(0);
    if(res1 > res2) printf("%d",res1);
    else printf("%d",res2);
    

    return 0;
}