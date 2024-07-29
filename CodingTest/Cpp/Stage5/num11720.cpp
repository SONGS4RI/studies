#include<iostream>
using namespace std;
int main()
{
    int n,sum=0;
    char num;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> num;
        sum += (int)num - 48;
    }
    cout << sum;
    return 0;
}