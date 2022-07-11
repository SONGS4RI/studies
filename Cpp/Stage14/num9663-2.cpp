#include<iostream>
#include<vector>
using namespace std;
int n,res=0;
vector<int> visited(15);
bool check(int cnt)
{
    for(int i=0;i<cnt;i++)
    {
        if(visited[i]==visited[cnt] || cnt-i == abs(visited[i]-visited[cnt]))
        {
            return 0;
        }
    }
    return 1;
}
void queen(int cnt)
{
    if(cnt==n)
    {
        res++;
        return;
    }
    for(int i=0;i<n;i++)
    {
        visited[cnt] = i;
        if(check(cnt))
        {
            queen(cnt+1);
        }
    }
}
int main()
{
    cin >> n;
    queen(0);
    cout << res;
    return 0;
}