#include<iostream>
using namespace std;
int main()
{
    int n,arr[10001],dp[10001]={0,};
    cin >> n;
    for(int i=1;i<=n;i++) cin >> arr[i];
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = max(arr[1],arr[2]) + arr[3];
    for(int i=4;i<=n;i++) dp[i] = max(dp[i-3]+arr[i-1]+arr[i],dp[i-1]);
    cout << dp[n];
    return 0;
}