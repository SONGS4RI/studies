#include<iostream>
using namespace std;
int m,n;
int arr[9]={0,};
bool visited[9]={0,};
void dfs(int cnt)
{
    if(cnt==m)
    {
        for(int i=0; i<cnt;i++) cout << arr[i] << " ";
        cout << "\n";
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                visited[i]= true;
                arr[cnt]=i;
                dfs(cnt+1);
                visited[i]= false;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    dfs(0);
    return 0;
}