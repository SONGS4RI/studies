#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    int cnt=1;
    getline(cin, str);
    for(int i=1;i<str.length()-1;i++)
    {
        if(str[i] == (char)32) cnt++;
    }
    if(str==" ") cnt = 0;
    cout << cnt;
    return 0; 
}