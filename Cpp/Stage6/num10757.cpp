#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void func(string a,int *res)
{
    int err=0;
    for(int i=a.length()-1;i>=0;i--)
        {
            if(res[i]!=0)
            {
                cout << res[i];
                err =1;
            }
            else if(res[i]==0 && err == 0) err =0;
            else cout << res[i];
        }
    if(err==0) cout << 0;
}
int main()
{
    int up=0,res[10003]={0,},err=0;
    string a,b,temp;
    cin >> a >> b;
    if(a.length() < b.length())
    {
        temp = a;
        a = b;
        b=temp;
    }
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    for(int i=0; i<b.length(); i++)
    {
        res[i] = (a[i] - '0' + b[i] -'0' + up)%10;
        if(a[i] - '0' + b[i] -'0' + up > 9) up = 1;
        else up =0;
    }
    for(int i = b.length(); i<a.length();i++)
    {
        res[i] = a[i] + up -'0';
        up =0;
    }
    if(up==1)
    {
        cout << 1;
        func(a,res);
    }
    else func(a,res);
    return 0;
}
