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
        scanf("%s",arr[i].c1);
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
}