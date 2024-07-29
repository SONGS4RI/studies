#include<iostream>
using namespace std;
int func(int num)
{
    if(num==1) return 0;
    for(int i=2; i<num-1;i++)
    {
        if((num/i)*i==num) return 0;
    }
    return 1;
}
int main()
{
    int cnt=0,n;
    cin >> n;
    int num;
    for(int i=0;i<n;i++)
    {
        cin >> num;
        if(func(num)) cnt++;
    }
    cout << cnt;
    return 0;
}