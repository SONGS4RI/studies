#include<iostream>
using namespace std;
int main()
{
    int t,k,n,arr[15][15]={0,},q=1;
    cin >> t;
    for(int i=1; i<15;i++) arr[1][i] = arr[1][i-1] + q++;
    for(int i=2; i<15;i++)
    {
        for(int j=1; j<15;j++)
        {
            arr[i][j] = arr[i-1][j]+arr[i][j-1];
        }
    }
    for(int i=0; i<t;i++)
    {
        cin >> k >> n;
        cout << arr[k][n] << "\n";
    }
    return 0;
}