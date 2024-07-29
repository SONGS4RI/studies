#include<iostream>
using namespace std;
int main()
{
    int q,w;
    cin >> q >> w;
    if(q>w) cout << ">";
    else if(q<w) cout << "<";
    else cout << "==";
    return 0;
}