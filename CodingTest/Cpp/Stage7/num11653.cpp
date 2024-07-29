#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for(int i=2; i<=n;i++)
    {
        if((n/i)*i==n)
        {
            cout << i << "\n";
            n /= i--;
        }
    }
    return 0;
}