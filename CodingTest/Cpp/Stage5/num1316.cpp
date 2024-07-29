#include<iostream>
using namespace std;
int main()
{
    int t,cnt=0;
    string str;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> str;
        for(int j=0; j<str.length()-1;j++)
        {
            int var = 0,err=0;
            for(int k=j+1; k<str.length();k++)
            {

                if(str[j]==str[k]) var++;
                else var =0;
                if(str[j]==str[k] && k-j != var)
                {
                    cnt--;
                    err=1;
                    break;
                }
            }
            if(err==1) break;
        }
        cnt++;
    }
    cout << cnt;
    return 0;
}
