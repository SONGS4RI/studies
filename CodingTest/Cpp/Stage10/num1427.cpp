#include<iostream>
#include<algorithm>
using namespace std;
bool compare(int a, int b)
{
    return a>b;
}
int main()
{
    int n,arr[10]={0,},i=0;
    cin >> n;
    while(n>0)
    {
        arr[i] = n%10;
        n/=10;
        i++;
    }
    sort(arr,arr+i,compare);
    for(int j=0;j<i;j++) cout << arr[j];
    return 0;
}