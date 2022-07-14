#include<iostream>
#include<math.h>

using namespace std;

int n,arr[21][21],res_min=10000;
bool visited[21];

void dfs(int cnt,int num)
{
    if(cnt==n/2)
    {
        int start=0,link=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(visited[i]==true && visited[j]==true) start +=arr[i][j];
                else if(visited[i]==false && visited[j]==false) link +=arr[i][j];
            }
        }
        int temp = abs(start - link);
        if(temp<res_min) res_min = temp;
        return;
    }
    for(int i=num;i<n;i++)
    {
        visited[i] = true;
        dfs(cnt+1,i+1);
        visited[i] = false;
    }
}
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) cin >> arr[i][j];
    }
    dfs(0,1);
    cout << res_min;
}