#include<iostream>
#include<vector>
using namespace std;
int arr[9][9]={0,},zero=0,flag=0;
bool check(int i,int j, int num)
{
    for(int x=0;x<9;x++)
    {
        if(arr[x][j]==num && x!=i) return 0;
        else if (arr[i][x]==num && x!=j) return 0;
    }
    for(int x=i-i%3;x<=i-i%3+2;x++)
    {
        for(int y=j-j%3;y<=j-j%3+2;y++)
        {
            if(arr[x][y]==num)
            {
                if(x!=i&&y!=j) return 0;
            }
        }
    }
    return 1;

}
void dfs(int cnt)
{
    if(cnt==zero)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++) cout << arr[i][j] << " ";
            cout << "\n";
            flag = 1;
            return;
        }
    }
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(arr[i][j]==0)
            {
                for(int k=1;k<=9;k++)
                {
                    if(check(i,j,k))
                    {
                        arr[i][j]== k;
                        dfs(cnt+1);
                        if(flag==1) break;
                    }
                }
                if(flag==1) break;
            }
        }
        if(flag==1) break;
    }
    return;

}
int main()
{   
    int num;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin >> arr[i][j];
            if(arr[i][j]==0) zero++;
        } 
    }
    dfs(0);
    return 0;
}