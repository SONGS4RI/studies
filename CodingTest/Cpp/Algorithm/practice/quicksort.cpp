#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
    int temp = *a;
    *a =*b;
    *b = temp;
}
void quicksort(int arr[],int left,int right)
{
    if(left>=right) return;
    int pivot = left;
    int start = left+1;
    int end = right;
    while(start<=end)
    {
        while(arr[pivot]>=arr[start] && start<=right) start++;
        while(arr[pivot]<=arr[end] && end>left) end--;
        if(start>end) swap(arr[pivot],arr[end]);
        else swap(arr[start],arr[end]);
    }
    quicksort(arr,left,end-1);
    quicksort(arr,end+1,right);
}
int main()
{
    int arr[] = {0,5,8,4,3,2,6,7,9,1};
    quicksort(arr,0,sizeof(arr)/sizeof(int)-1);
    for(int i=0;i<sizeof(arr)/sizeof(int);i++) cout << arr[i] << " ";
    return 0;
}