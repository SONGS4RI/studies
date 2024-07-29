#include<iostream>
using namespace std;
int main()
{
    int a,b,v,res;
    cin >> a >> b >> v;
    res = v/(a-b)+1;
    while(1)
    {
        if((a-b)*res+b>=v) res--;
        else
        {
            cout << res+1;
            break;
        }
    }
    return 0;
}