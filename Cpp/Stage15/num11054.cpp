#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n,num,dp1[1001],dp2[1001],ans[1001]={0,};
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        cin >> num;
        v.push_back(num);
        int temp =0;
        for(int j=0;j<i;j++)
        {
            if(v[i]>v[j]&&dp1[j]>temp) temp = dp1[j];
        }
        dp1[i]=temp+1;
        ans[i] += dp1[i];
    }
    for(int i=n-1;i>=0;i--)
    {
        int temp =0;
        for(int j=n-1;j>i;j--)
        {
            if(v[i]>v[j]&&dp2[j]>temp) temp = dp2[j];
        }
        dp2[i] = temp+1;
        ans[i] += dp2[i];
    }
    sort(ans,ans+n);
    cout << ans[n-1]-1;
    return 0;
}