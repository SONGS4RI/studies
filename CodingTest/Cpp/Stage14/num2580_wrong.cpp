#include<iostream>
#include<vector>
using namespace std;
int arr[9][9]={0,},zero=0;
bool check(int i,int j, int num)
{
    for(int x=0;x<9;x++)
    {
        if(arr[x][j]==num ) return false;
        if (arr[i][x]==num ) return false;
    }
    for(int x=i-i%3;x<=i-i%3+2;x++)
    {
        for(int y=j-j%3;y<=j-j%3+2;y++)
        {
            if(arr[x][y]==num) return false;
        }
    }
    return true;

}
void dfs(int cnt)
{
    if(cnt==zero)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++) cout << arr[i][j] << " ";
            cout << "\n";
        }
        exit(0);
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
                        arr[i][j]== 0;
                    }
                }
            }
        }
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