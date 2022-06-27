#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    vector<string> v;
    cin >> s;
    for(int i=0; i<s.length();i++)
    {
        for(int k=0;k<i+1;k++) // 2times
        {
            string temp;
            for(int j=0;j<s.length()-i;j++) // i=1 , 
            {
                temp +=s[j+k];
            }
            v.push_back(temp);
        }
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    cout << v.size();
    return 0;
}