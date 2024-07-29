#include<iostream>
using namespace std;
int main()
{
    int n,m,min=33;
    cin >> n >> m;
    char arr[n][m];
    for(int i=0; i<n;i++) cin >> arr[i];
    for(int i=0;i<=n-8;i++)
    {
        for(int j=0;j<=m-8;j++)
        {
            int cnt =0;
            for(int k=i;k<i+8;k++)
            {
                for(int l=j;l<j+8;l++)
                {
                    if((k+l)%2==(i+j)%2)
                    {
                        if(arr[k][l]!=arr[i][j]) cnt++;
                    }
                    else
                    {
                        if(arr[k][l]==arr[i][j]) cnt++;
                    }
                }
            }
            if(cnt>32) cnt = 64-cnt;
            if(cnt<min) min=cnt;
        }
    }
    cout << min;
    return 0;
}