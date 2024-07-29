#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,stair[301],dp[301]={0,};
    cin >> n;
    for(int i=1;i<=n;i++) cin >>stair[i];
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];
    dp[3] = max(stair[1],stair[2]) + stair[3];
    for(int i=4;i<=n;i++) dp[i] = max(stair[i] + dp[i-2], stair[i]+stair[i-1] +dp[i-3]);
    cout << dp[n];
    return 0;   
}