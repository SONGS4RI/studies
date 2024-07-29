#include<iostream>
using namespace std;
int n;
long long arr[101]={0,};
long long tri(int n)
{
    if(n==1 || n==2 || n==3) return 1;
    else if (n==4 || n==5) return 2;
    if(arr[n]!=0) return arr[n];
    else return arr[n] = tri(n-1) + tri(n-5);
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << tri(n) << "\n";
    }
    return 0;
}