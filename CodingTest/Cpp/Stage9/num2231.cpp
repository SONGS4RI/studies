#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for(int i=n-54; i<n;i++)
    {
        int res = i,j=i;
        while(j>0)
        {
            res += j%10;
            j/=10;
        }
        if(res==n)
        {
            cout << i;
            break;
        }
        if(i==n-1 && res!=n) cout << 0;
    }
    return 0;
}