#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,num,cnt=0;
    map<int,bool> m1;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> num;
        m1.insert(pair<int,bool>(num,true));
    }
    for(int i=0;i<m;i++)
    {
        cin >> num;
        if(m1[num]) cnt++;
        else m1.insert(pair<int,bool>(num,true));
    }
    cout << m1.size() -cnt;  
    return 0;
}