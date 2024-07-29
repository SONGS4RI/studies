#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int Bsearch(int arr[], int target,int cnt)
{
    int low = 0;
    int high = cnt-1;
    int mid;

    while(low<=high)
    {
        mid = (low+high)/2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] > target) high = mid-1;
        else low = mid +1;
    }
    return -1;
}
int unique(int *arr,int size)
{
    int i,j=0;
    for(i=1; i<size;i++)
    {
        if(arr[j]==arr[i]) continue;
        arr[++j] = arr[i];
    }
    return ++j;
}
int compare(const void *a,const void *b)
{
    int A = *(int*) a;
    int B = *(int*) b;
    if(A>B) return 1;
    else if(A<B) return -1;
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    int res[n];
    for(int i=0; i<n;i++) arr[i] =0;
    for(int i=0;i<n;i++)
    {
        scanf(" %d",&arr[i]);
    }
    for(int i=0; i<n; i++) res[i] = arr[i];
    qsort(arr,n,sizeof(int),compare);
    int cnt = unique(arr,n);  // n-cnt °¡ Áßº¹°¹¼ö
    for(int i=0; i<n ;i++)
    {
        printf("%d ",Bsearch(arr,res[i],cnt));
    }
    return 0;
}
