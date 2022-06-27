#include<iostream>
#include<map>
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
    for(int i=0;i<n;i++)
    {
        cin >> s;
        m1[s] = true;
    }
    for(int i=0;i<m;i++)
    {
        cin >> s;
        if(m1[s]) cnt++;
    }
    cout << cnt;
    return 0;
}