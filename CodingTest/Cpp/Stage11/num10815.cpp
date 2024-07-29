#include<iostream>
#include<algorithm>
#include<vector>
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
    cin >> m;
    sort(v1.begin(),v1.end());
    vector<int> v2(m);
    for(int i=0;i<m;i++) cin >> v2[i];
    for(int i=0;i<m;i++)
    {
        if(binary_search(v1.begin(),v1.end(),v2[i])) cout << "1 ";
        else cout << "0 ";
    }
    return 0;
}