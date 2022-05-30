#include<stdio.h>
typedef struct
{
    char num;
    int index;
}res;

int compare(const void *a,const void *b)
{
    res A = *(res*) a;
    res B = *(res*) b;
    if(A.num>B.num) return 1;
    else if(A.num<B.num) return -1;
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    res arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%s ",&arr[i].num);
        arr[i].index = i;
    }
    qsort(arr,n,sizeof(res),compare);
    

    return 0;
}