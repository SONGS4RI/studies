#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool compare(pair<int,string>a,pair<int,string>b)
{
    return a.first < b.first;
}
int main()
{
    int n,a;
    string b;
    vector<pair<int,string>> v;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    stable_sort(v.begin(),v.end(),compare);
    for(int i=0; i<n;i++) cout << v[i].first << " " << v[i].second << "\n";
    return 0;
}