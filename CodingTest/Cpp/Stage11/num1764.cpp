#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,cnt=0;
    string s;
    map<string,bool> m1;
    cin >> n >> m;
    vector<string> res;
    for(int i=0;i<n;i++)
    {
        cin >> s;
        m1[s] =true;
    }
    for(int i=0;i<m;i++)
    {
        cin >> s;
        if(m1[s])
        {
            res.push_back(s);
            cnt++;
        }
    }
    sort(res.begin(),res.end());
    cout << cnt << "\n";
    for(int i=0;i<cnt;i++) cout << res[i] << "\n" ;
    
    return 0;
}