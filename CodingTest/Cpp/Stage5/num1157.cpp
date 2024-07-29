#include<iostream>
using namespace std;
int main()
{
    string s;
    int alpha[26] = {0,},max=0,idx;
    cin >> s;
    for(int i=0; i<s.length();i++)
    {
        if((int)s[i]<97) alpha[(int)s[i]-65]++;
        else alpha[(int)s[i]-97]++;
    }
    for(int i=0; i<26;i++)
    {
        if(max<alpha[i])
        {
            max=alpha[i];
            idx = i;
        }
        else if(max == alpha[i] && max != 0) idx = -1;
    }
    if(idx == -1) cout << "?";
    else cout << (char)(65+idx);
    return 0;
}