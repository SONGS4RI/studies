#include<iostream>
using namespace std;
int main()
{
    int n,cnt=0,num1=0,res;
    cin >> n;
    res =n;
    while(1)
    {
        cnt++;
        num1 = (n%10)*10 + ((n/10)+n%10)%10;
        if(res==num1) break;
        n = num1;
    }
    cout << cnt;
    return 0;
}
