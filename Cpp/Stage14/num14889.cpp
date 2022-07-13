#include<iostream>
#include<vector>
using namespace std;
int n,res_min=100,sel[10];
int arr[21][21]={0,};
bool visited[21]={0,};
void func(int cnt,int res,int sel[],int arr[][21])
{
    for(int i=1;i<=cnt;i++)
        {
            for(int j=1;j<=cnt;j++) // 1,2,3
            {
                if(i!=j) res+= arr[sel[i]][sel[j]];
            }
        }
}
void dfs(int cnt, bool visited[], int arr[][21],int num)
{
    if(cnt == n/2)
    {
        int res_a=0,res_b=0,k=0;
        func(cnt,res_a,sel,arr);
        for(int i=1;i<=n;i++)
            if(!visited[i]) sel[k++] = i;
        func(cnt,res_b,sel,arr);
        if(abs(res_a-res_b)<res_min) res_min = abs(res_a-res_b);
    }
    
    for(int i=num;i<=n;i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            sel[cnt] = i;
            dfs(cnt+1,visited,arr,num+1);
            visited[i] = false;
        }
    }
}
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) cin >> arr[i][j];
    dfs(0,visited,arr,1);
    cout << res_min;
    return 0;
}