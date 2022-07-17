#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,res_max=0;
    cin >> n;
    int tri[n][n];
    int dp[n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i+1;j++)
        {
            cin >> tri[i][j];
            dp[i][j] = 0;
        }
        for(int j=i+1;j<n;j++)
        {
            tri[i][j] = 0;
            dp[i][j] = 0;
        } 
    }
    dp[0][0] = tri[0][0];
    for(int i=1;i<n;i++)
    {
        dp[i][0] = dp[i-1][0] + tri[i][0];
        for(int j=1;j<i+1;j++) dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + tri[i][j];
    }
    for(int i=0;i<n;i++) if(dp[n-1][i]>res_max) res_max =dp[n-1][i];
    
    cout << res_max;
    return 0;
}