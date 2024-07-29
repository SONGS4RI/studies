#include<iostream>
using namespace std;
#define x 1000000000;

int n;
long long dp[101][10];

int main()
{
    cin >> n;
    dp[1][0] = 0;
    for(int i=1; i<=9;i++) dp[1][i] = 1;
    for(int i=2; i<=n;i++)
    {
        for(int j=1;j<=8;j++) dp[i][j] = (dp[i-1][j-1]+dp[i-1][j+1])%x;
        dp[i][0] = (dp[i-1][1])%x;
        dp[i][9] = (dp[i-1][8])%x;
    }
    long long sum = 0;
    for(int i=0;i<=9;i++) sum += dp[n][i]%x;

    cout << sum%x;
    return 0;
}