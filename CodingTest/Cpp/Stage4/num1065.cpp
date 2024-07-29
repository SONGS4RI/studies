#include<iostream>
using namespace std;
int han(int n)
{
    int q,w,e;
    q = n/100;
    w = (n/10)%10;
    e = n%10;
    if(n<100) return 1;
    else if(q-w == w-e) return 1;
    return 0;
}
int main()
{
    int n, cnt=0;;
    cin >> n;
    for(int i =1; i<=n ; i++)
    {
        cnt += han(i);
    }
    cout << cnt;
    return 0;
}