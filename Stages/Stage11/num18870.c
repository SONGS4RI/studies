#include<stdio.h>
#include<string.h>

int Bsearch(int arr[], int target)
{
    int low = 0;
    int high = strlen(arr)-1;
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
    for(int i=1; i<size;i++)
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
    for(int i=0; i<n;i++) arr[i] =0;
    for(int i=0;i<n;i++)
    {
        scanf(" %d",&arr[i]);
    }
    qsort(arr,n,sizeof(int),compare);
    

    return 0;
}
