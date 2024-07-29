#include<iostream>
using namespace std;
int fac(int n,int res)
{
     if(n>1) return fac(n-1,res*n);
     else return res;
}
int main()
{
    int n,k;
    cin >> n >> k;
    if(k>=0 && k<=n) cout << fac(n,1)/(fac(k,1)*fac(n-k,1));
    else cout << 0;
    return 0;
}