#include<stdio.h>
int main()
{
    int a,b,v,move,res_a,res_b ;
    scanf("%d %d %d",&a,&b,&v);
    move = a-b;
    res_b = v-a;
    res_a = (v - a)/( move );

    if(res_b%move==0) printf("%d",res_a+1);
    else printf("%d",res_a+2);

    return 0;
}
