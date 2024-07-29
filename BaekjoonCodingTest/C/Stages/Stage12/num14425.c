#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define var 500

typedef struct 
{
    char arr[var];
    int len;
}strarr;

int compare(const void *a,const void *b)
{
    strarr A = *(strarr*) a;
    strarr B = *(strarr*) b;
    if(A.len>B.len) return 1;
    else if(A.len<B.len) return -1;
    else
    {
        for(int i=0;i<strlen(A.arr);i++)
        {
            if(A.arr[i]>B.arr[i]) return 1;
            else if(A.arr[i]<B.arr[i]) return -1;
        }
    }
    return 0;
}

int main()
{
    int n,m;
    scanf("%d",&n);
    strarr arr1[n];
    scanf("%d",&m);
    strarr arr2[m];

    for(int i=0; i<n; i++)
    {      
        scanf("%s",&arr1[i].arr);
        arr1[i].len = strlen(arr1[i].arr);
    } 
    for(int i=0; i<m; i++)
    {
        scanf("%s",&arr2[i]);
        arr2[i].len = strlen(arr2[i].arr);
    } 
    qsort(arr2,m,sizeof(strarr),compare);

    

    printf("--------------\n");
    for(int i=0; i<m;i++) printf("%s\n",arr2[i].arr);
    return 0;
}