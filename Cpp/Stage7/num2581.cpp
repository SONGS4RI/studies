#include<iostream>
using namespace std;
int main()
{
    int m,n,sum=0,min=0;
    cin >> m >> n;
    int arr[n+1] = {1,1,0,};
    for(int i=2; i<=n;i++)
    {
        for(int j=2;i*j<=n;j++)
        {
            arr[i*j] = 1;
        }
    }
    for(int i=n;i>=m;i--)
    {
        if(arr[i]==0)
        {
            sum += i;
            min = i;
        }
    }
    if(sum == 0) cout << -1;
    else cout << sum << "\n" << min;
    return 0;
}