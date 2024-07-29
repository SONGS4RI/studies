#include<iostream>
using namespace std;
int func(int x,int res,int i)
{
    res = res + i;
    if(x>res) return func(x,res,++i);
    else
    {
        if(i%2==0) cout << i-(res-x) << "/" << res-x+1;
        else cout << res-x+1 << "/" << i-(res-x);
    }
    return 0;
}
int main()
{
    int x;
    cin >> x;
    func(x,0,1);
    return 0;
}
