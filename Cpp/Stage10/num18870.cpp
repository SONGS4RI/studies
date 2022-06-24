#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool compare(pair<int,int>a,pair<int,int>b)
{
    return a.first < b.first;
}
int main()
{
    int n,num,cnt;
    vector<pair<int,int>> v,res;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> num;
        v.push_back(make_pair(num,i));
    }
    sort(v.begin(),v.end(),compare);
    

    
    return 0;
}