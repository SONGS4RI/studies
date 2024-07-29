#include<iostream>
#include<map>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    string s;
    map<string,int> m1;
    string str[100001];
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> s;
        m1.insert(pair<string,int>(s,i));
        str[i] = s;
    }
    for(int i=1;i<=m;i++)
    {
        cin >> s;
        if(isdigit(s[0])) cout << str[stoi(s)] << "\n";
        else cout << m1[s] << "\n";
    }
    return 0;
}