#include<iostream>
using namespace std;
int main()
{
    int x,dp[1000001]={0,};
    cin >> x;    
    for(int i=2;i<=x;i++)
    {
        if(i%6==0) dp[i] = min(min(min(dp[i/3]+1,dp[i/2]+1),dp[i-1]+1),dp[i-2]+2);
        else if(i%3==0) dp[i] = min(min(dp[i/3]+1,dp[i-1]+1),dp[i-2]+2);
        else if(i%2==0)  dp[i] = min(min(dp[i/2]+1,dp[i-1]+1),dp[i-2]+2);
        else dp[i] = min(dp[i-1]+1,dp[i-2]+2);
    }
    cout << dp[x];
    return 0;
}