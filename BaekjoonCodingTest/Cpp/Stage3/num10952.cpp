#include<iostream>
using namespace std;
int main()
{
    int q,w;
    while(1)
    {
        cin >> q >> w;
        if(q==0 &&w==0) break;
        else cout << q+w << "\n";
    }
    return 0;
}