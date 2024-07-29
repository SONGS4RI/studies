#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void quicksort(int arr[],int left,int right)
{
    if(left>=right) return;
    int pivot = left;
    int start = left + 1;
    int end = right;
    while(start<=end)
    {
        while(arr[start]<=arr[pivot] && start<=right) start++;
        while(arr[end]>=arr[pivot] && end>left) end--;
        if(start>end) swap(arr[pivot],arr[end]);
        else swap(arr[start],arr[end]);
    }
    quicksort(arr,left,end-1);
    quicksort(arr,end+1,right);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++) cout << arr[i] << "\n";
    return 0;
}