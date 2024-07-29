#include<iostream>
using namespace std;
void eratos(int* arr,int n)
{
    if (n<=1) return;
    for(int i=2;i*i<=n;i++)
    {
        if(arr[i]==0)
        {
            for(int j=i*i;j<=n;j+=i) arr[j] = 1;
        }
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n = 1,arr[10001] = {1,1,0,},t;
    eratos(arr,10000);
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