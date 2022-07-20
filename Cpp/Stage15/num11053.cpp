#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n,num,res=0;
    cin >> n;
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++)
    {
        cin >> num;
        arr.push_back(pair<int,int>(num,i));
    }
    sort(arr.begin(),arr.end());
    for(int i=1;i<n;i++)
    {
        if(arr[i].first==arr[i-1].first)
        {
            arr.erase(arr.begin()+i);
            i--;
            n--;
        }
    }
    for(int i=0;i<arr.size();i++)
    {
        int cnt=1;
        for(int j=0;j<i;j++)
        {
            if(arr[j].second<arr[i].second) cnt++;
        }
        if(cnt>res) res = cnt;
    }
    cout << res;
    return 0;
}