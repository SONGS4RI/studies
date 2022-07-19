#include<iostream>
using namespace std;
int main()
{
    int n,arr[10001],dp[10001]={0,};
    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    for(int i=3;i<=n;i++) dp[i] = max(dp[i-1],max(arr[i]+dp[i-2],arr[i]+arr[i-1]+dp[i-3]));
    cout << dp[n];
    return 0;
}