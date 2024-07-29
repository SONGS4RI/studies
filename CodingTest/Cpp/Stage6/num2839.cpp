#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if(n==4 ||n==7) cout << -1;
    else if(n%5==0) cout << n/5;
    else if(n%5==4 || n%5==2) cout << n/5+2;
    else if(n%5==3 || n%5==1) cout << n/5+1;
    return 0;
}