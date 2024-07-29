#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
    int n,num,dp[1001]={0,},res=0;
    vector<int> arr;
    cin >> n;
    
    for(int i=0;i<n;i++)
    {
        cin >> num;
        arr.push_back(num);
        int dp_max =0;
        for(int j=0;j<arr.size();j++)
        {
            if(arr[i]>arr[j])
            {
                if(dp_max<dp[j]) dp_max = dp[j];
            }
        }
        dp[i] = dp_max +1;
        res = max(res,dp[i]);
    }
    cout << res;
}