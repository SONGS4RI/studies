#include<iostream>
using namespace std;
int main()
{
    int n = 1,arr[10001] = {1,1,0,},t;
    for(int i=2;i<10001;i++)
    {
        for(int j=2;i*j<=10000;j++) arr[i*j] =1;
    }
    cin >> t;
    for(int i=0; i<t; i++)
    {
        cin >> n;
        for(int j=n/2; j<n;j++)
        {
            if(arr[j]==0&&arr[n-j]==0)
            {
                cout << n-j << " " << j << "\n";
                break;
            }
        }     
    }
    return 0;
}