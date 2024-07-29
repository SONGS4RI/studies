#include<iostream>
using namespace std;
int main()
{
    int q;
    cin >> q;
    if(q%4==0 && q%100!=0 || q%400==0) cout << 1;
    else cout << 0;
    return 0;
}