#include<stdio.h>
#include<stdlib.h>
int main()
{
    char input[15] = {0,};
    int i=0, sum=0;
    scanf("%s",&input);

    while(input[i]!=0)
    {
        if(65<=input[i] && input[i]<=67) sum+=3;
        else if(68<=input[i] && input[i]<=70) sum+=4;
        else if(71<=input[i] && input[i]<=73) sum+=5;
        else if(74<=input[i] && input[i]<=76) sum+=6;
        else if(77<=input[i] && input[i]<=79) sum+=7;
        else if(80<=input[i] && input[i]<=83) sum+=8;
        else if(84<=input[i] && input[i]<=86) sum+=9;
        else if(87<=input[i] && input[i]<=90) sum+=10;
        else exit(0);           
        i++;
    }
    printf("%d",sum);
    
    return 0;
}