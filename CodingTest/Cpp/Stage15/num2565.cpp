#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,arr[501]={0,},left,right,dp[501]={0,}, res=0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> left >> right;
        arr[left] = right;
    }
    for(int i=1;i<501;i++)
    {
        if(arr[i]!=0)
        {
            int dp_max = 0;
            for(int j=1;j<i;j++)
            {
                if(arr[j]<arr[i]&&dp[j]>dp_max&&arr[j]!=0) dp_max = dp[j];
            }
            dp[i] = dp_max+1;
            res = max(res,dp[i]);
        }
    }
    cout << n-res;
    return 0;
}