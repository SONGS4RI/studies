#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cin >> m >> n;
    int arr[n+1] = {1,1,0,};
    for(int i=2; i<=n;i++)
    {
        for(int j=2;i*j<=n;j++)
        {
            arr[i*j] = 1;
        }
    }
    for(int i=m;i<=n;i++)
    {
        if(arr[i]==0) cout << i << "\n";
    }
    return 0;
}