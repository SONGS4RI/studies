#include<iostream>
using namespace std;
int main()
{
    int q,w,e;
    cin >> q >> w >> e;
    if(q == w && w == e) cout << 10000 + q*1000;
    else if(q != w && w!=e && e!= q)
    {
        if (q>w && q>e) cout << q*100;
        else if (w>q && w>e) cout << w*100;
        else cout << e*100;
    }
    else
    {
        if(q == w) cout << 1000 + q*100;
        else if(w==e) cout << 1000 + w*100;
        else cout << 1000 + e*100;
    }
    return 0;
}