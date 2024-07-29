#include<iostream>
using namespace std;
int func(int n, int res, int i)
{
    res = res + i*6;
    if(n>res) return func(n,res,++i);
    else return i+1;
}
int main()
{
    int n;
    cin >> n;
    cout << func(n,1,0);
    return 0;
}
