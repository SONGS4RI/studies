#include<iostream>
#include<string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,cnt=0;
    cin >> n;
    cin >> m;
    string s1[n+1];
    for(int i=0;i<n;i++) cin >> s1[i];
    string res[m+1];
    for(int i=0;i<m;i++) cin >> res[i];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s1[i].compare(res[j])==0)
            {
                cnt++;
                break;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}