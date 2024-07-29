#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int num[n];
    for(int i=0;i<n;i++) cin >> num[i];
    int dp[n]={num[0],},res=dp[0];
    for(int i=1;i<n;i++)
    {
        dp[i] = max(dp[i-1]+num[i],num[i]);
        res = max(res,dp[i]);
    } 
    cout << res;
    return 0;
}