#include<iostream>
using namespace std;
int main()
{
    int x,dp[1000001]={0,};
    cin >> x;
    
    
    for(int i=2;i<=x;i++)
    {
        if(i%3==0) dp[i] = dp[i/3]+1;
        else if(i%2==0)  dp[i] = dp[i/2]+1;
        else dp[i] = dp[i-1]+1;
    }
    return 0;
}