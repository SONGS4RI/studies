#include<iostream>
using namespace std;
int n,arr[1000002]={0,};
int func(int n)
{
    if(n==2) return 2;
    else if(n==1) return 1;
    if(arr[n]!=0) return arr[n];
    else return arr[n] = (func(n-1)%15746 + func(n-2)%15746)%15746;
}
int main()
{
    arr[1] = 1;
    arr[2] = 2;
    cin >> n;
    cout << func(n);

    return 0;
}