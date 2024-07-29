#include<iostream>
#include<cmath>
using namespace std;
int notfive(int num)
{
    while(1)
    {
        if(num%5==0) break;
        else num--;
    }
    return num;
}
int func5(int n)
{ 
    int cnt = 0;
    for(int i=1;i<16;i++) cnt+= n/pow(5,i);
    return cnt;
}
int func2(int n)
{
    int res=0;
    while(n>1)
    {
        res+=n/2;
        n-=2;       
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,cnt5=0,cnt2=0,temp,q,w,temp2;
    cin >> n >> m;
    temp = n-m;
    q = n;
    w = m;
    temp2 = temp;

    n = notfive(n);
    m = notfive(m);
    temp = notfive(temp);

    cnt5 = func5(n) - func5(m) - func5(temp);
    cnt2 = func2(q) - func2(w) - func2(temp2);
    if(cnt2<0) cnt2 = cnt5;
    temp = cnt2 > cnt5 ? cnt5 : cnt2;
    cout << temp;
    return 0;
}