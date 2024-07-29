#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int flag;
    int age;
    char name[101];
}reg;
int compare(const void *a,const void *b)
{
    reg A = *(reg*)a;
    reg B = *(reg*)b;

    if(A.age>B.age) return 1;
    else if(A.age==B.age)
    {
        if(A.flag>B.flag) return 1;
        else return -1;
    }
    return -1;
}
int main()
{
    int n;
    scanf("%d",&n);
    reg arr[n];
    for(int i=0; i<n; i++)
    { 
        scanf("%d %s",&arr[i].age,&arr[i].name);
        arr[i].flag = i;
    }
    qsort(arr,n,sizeof(reg),compare);
    for(int i=0; i<n; i++)
    {
        printf("%d %s\n",arr[i].age,arr[i].name);
    }
    return 0;
}