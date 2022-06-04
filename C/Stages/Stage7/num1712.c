#include <stdio.h>
#include <stdlib.h>
int main()
{
    long long a, b, c, total, income, i=1,res, sales;

    scanf("%lld %lld %lld",&a,&b,&c);
    sales = c-b;
    if( sales<=0 ) 
        {
            printf("-1");
            exit(0);
        }  
          
    res=a/sales+1;
    printf("%lld",res);
    return 0;
}