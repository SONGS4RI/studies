#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int gcd(int a,int b)
{
    if(b>0)return gcd(b,a%b);
    else return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,res,temp;
    vector<int> v;
    cin >> n;
    int num[n];
    for(int i=0;i<n;i++) cin >> num[i];
    sort(num,num+n);
    res = num[1]-num[0];
    for(int i=2;i<n;i++)
    {
        res = gcd(res,num[i]-num[i-1]);
    }
    for(int i=2;i*i<=res;i++)
    {
        if(res%i==0)
        {
            v.push_back(i);
            v.push_back(res/i);
        }
    }
    v.push_back(res);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=0;i<v.size();i++) cout << v[i] << " ";
    return 0;
}