#include<iostream>
using namespace std;
int func(int n,int k)
{
    int num = 0;
    while(1)
    {
        if((n/k)*k==n)
        {
            n /=k;
            num++;
        }
        else break;
    }
    return num;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,two=0,five=0;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        two += func(i,2);
        five += func(i,5);
    }
    int res = two > five ? five : two;
    cout << res;

    return 0;
}