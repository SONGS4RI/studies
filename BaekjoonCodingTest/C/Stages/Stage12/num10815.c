#include<stdio.h>
#include<stdlib.h>
int Bsearch (int arr[],int var,int n)
{
    int low = 0;
    int high = n;
    int mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(var==arr[mid]) return 1;
        else if(var<arr[mid]) high = mid-1;
        else low = mid+1;
    }
    return 0;
}
int compare(const void *a,const void *b)
{
    int A = *(int*)a;
    int B = *(int*)b;
    if(A>B) return 1;
    else if(A<B) return -1;
    return 0;
}
int main()
{
    int n,m;
    scanf("%d",&n);
    int arr1[n];
    for(int i=0; i<n; i++) scanf(" %d",&arr1[i]);
    scanf("%d",&m);
    int arr2[m];
    for(int i=0; i<m; i++) scanf(" %d",&arr2[i]);
    qsort(arr1,n,sizeof(int),compare);
    for(int i=0; i<m;i++)
    {
        int res = Bsearch(arr1,arr2[i],n);
        printf("%d ",res);
    }

    return 0;
}