#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    vector<int> res(v);
    sort(res.begin(),res.end());
    res.erase(unique(res.begin(),res.end()),res.end());
    for(int i=0;i<n;i++)
    {
        cout << lower_bound(res.begin(),res.end(),v[i]) -res.begin() << " ";
    }
    return 0;
}