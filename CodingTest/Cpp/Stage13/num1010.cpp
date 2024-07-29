#include<iostream>
using namespace std;
int main()
{
    int t,n,m,arr[31][31]={0,};
    for(int i=1;i<31;i++) arr[1][i] = arr[1][i-1] +1;
    for(int i=2;i<31;i++)
    {
        for(int j=i;j<31;j++)
        {
            if(i==j) arr[i][j] = 1;
            else arr[i][j] = arr[i][j-1]+arr[i-1][j-1];
        }
    }
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> n >> m;
        cout << arr[n][m] << "\n";
    }
    return 0;
}