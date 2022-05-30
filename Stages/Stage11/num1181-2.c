<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
    char c1[50];
    int len;
}dic;
int compare(const void *a,const void *b)
{
    dic A = *(dic*)a;
    dic B = *(dic*)b;

    if(A.len>B.len) return 1;
    else if(A.len==B.len)
    {
        for(int i=0;i<strlen(A.c1);i++)
        {
            if(A.c1[i]>B.c1[i]) return 1;
            else if(A.c1[i]<B.c1[i]) return -1;
        }
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d",&n);
    dic arr[n];
    for(int i=0; i<n; i++)
    {
        gets(arr[i].c1);
        arr[i].len = strlen(arr[i].c1);
    }
    qsort(arr,n,sizeof(dic),compare);
    for(int i=0; i<n; i++) 
    {
        for(int j=0; j<arr[i].len;j++)
        {
            if(arr[i].len!=arr[i+1].len && i!=n)
            {
                printf("%s\n",arr[i].c1);
                break;
            }
            if(arr[i].c1[j]!=arr[i+1].c1[j] && i!=n)
            {
                printf("%s\n",arr[i].c1);
                break;
            }
        }
        if(i==n) printf("%s\n",arr[i].c1);
    }
    return 0;
=======
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    char str[51];
    int len;
}Str;
int compare(const void *a, const void *b){
    Str s1 = *(Str*)a, s2 = *(Str*)b;
    if (s1.len < s2.len)
        return -1;
    else if (s1.len > s2.len)
        return 1;
    return strcmp(s1.str, s2.str);
}

int main(){
    int N, min = 0, max = 0;
    scanf("%d", &N);
    Str s[N];
    for (int i = 0; i < N; i++){
        scanf("%s", s[i].str);
        s[i].len = strlen(s[i].str);
    }
    qsort(s, N, sizeof(Str), compare);
    puts(s[0].str);
    for (int i = 1; i < N; i++)
        if (strcmp(s[i-1].str, s[i].str))
            puts(s[i].str);
>>>>>>> 33ecc529b2372dfe61231ca908c9c132016737d7
}