#include<iostream>
using namespace std;
int n,res_min=100000,sel[10];
int arr[21][21]={0,};
bool visited[21]={0,};
int func(int cnt,int sel[],int arr[][21])
{
    int res=0;
    for(int i=0;i<cnt;i++)
        {
            for(int j=0;j<cnt;j++)
            {
                res+= arr[sel[i]][sel[j]];
            }
        }
    return res;
}
void dfs(int cnt, bool visited[21], int arr[21][21])
{
    if(cnt == n/2)
    {
        int k=0,sel_b[n/2],temp;
        for(int i=1;i<=n;i++)
            if(!visited[i]) sel_b[k++] = i;
        temp = func(cnt,sel,arr) - func(cnt,sel_b,arr);
        if(abs(temp)<res_min) res_min = abs(temp);
    }
    
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            sel[cnt] = i;
            dfs(cnt+1,visited,arr);
            visited[i] = false;
        }
    }
}
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) cin >> arr[i][j];
    dfs(0,visited,arr);
    cout << res_min;
    return 0;
}