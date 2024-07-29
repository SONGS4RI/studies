#include<iostream>
using namespace std;
int main()
{
    int q,w,temp;
    while(1)
    {
        int flag =0;
        cin >> q >> w;
        if(q==0&&w==0) break;
        if(w%q==0) cout << "factor\n";
        else if(q%w==0) cout << "multiple\n";
        else cout << "neither\n";
    }
    return 0;
}