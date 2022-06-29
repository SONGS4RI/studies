#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int a,b,x,y;
    vector<pair<int,int>>v;
    for(int i=0;i<3;i++)
    { 
       cin >> a >> b;
       v.push_back(pair<int,int>(a,b));
    }
    sort(v.begin(),v.end());
    if(v[0].first != v[1].first && v[0].first != v[2].first) x = v[0].first;
    else if(v[0].first != v[1].first) x = v[1].first;
    else x = v[2].first;
    if(v[0].second != v[1].second && v[0].second != v[2].second) y = v[0].second;
    else if(v[0].second != v[1].second) y = v[1].second;
    else y = v[2].second;
    cout << x << " " << y;
    return 0;
}