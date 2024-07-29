#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool compare(pair<int,string>a,pair<int,string>b)
{
    if(a.first==b.first)
    {
        for(int i=0; i<a.first;i++)
        {
            if(a.second[i]!=b.second[i])
            {
                return a.second[i]<b.second[i];
            }
        }
        return 0;
    }
    else return a.first < b.first;
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,a;
    string b;
    vector<pair<int,string>> arr;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> b;
        a = b.length();
        arr.push_back(make_pair(a,b));
    }
    sort(arr.begin(),arr.end(),compare);

    for(int i=0;i<n-1;i++) 
    {
        if(arr[i].second==arr[i+1].second) continue;
        cout << arr[i].second << "\n";
    }
    cout << arr[n-1].second;
    return 0;
}