#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n;
    vector<int> v1(n);
    for(int i=0;i<n;i++) cin >> v1[i];
    sort(v1.begin(),v1.end());
    cin >> m;
    for(int i=0;i<m;i++)
    {
        cin >> n;
        cout << upper_bound(v1.begin(),v1.end(),n) - lower_bound(v1.begin(),v1.end(),n) << " ";
    }

    return 0;
}