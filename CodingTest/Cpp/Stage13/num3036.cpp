#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    if(b>0) return gcd(b,a%b);
    else return a;
}
int main()
{
    int n,a,b;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=1;i<n;i++)
    {
        a=gcd(arr[0],arr[i]);
        cout << arr[0]/gcd(arr[0],arr[i]) << "/" << arr[i]/gcd(arr[0],arr[i]) << "\n";
    }
    return 0;
}