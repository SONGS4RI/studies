#include<iostream>
using namespace std;
int main()
{
    int n = 1,arr[246913] = {1,1,0,};
    for(int i=2; i<=246913;i++)
        {
            for(int j=2;i*j<=246913;j++) arr[i*j] = 1;
        }
    while(n!=0)
    {
        cin >> n;
        int cnt=0;
        
        for(int i=n+1;i<=2*n;i++)
        {
            if(arr[i]==0) cnt++;
        }
        if(n!=0) cout << cnt << "\n";
    }
    return 0;
}