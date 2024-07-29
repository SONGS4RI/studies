#include<iostream>
using namespace std;
int arr[9][9];
bool check(int x, int y, int num)
{
    for(int i=0;i<9;i++)
    {
        if(arr[x][i]==num) return false;
        if(arr[i][y]==num) return false;
    }
    for(int i=x-x%3;i<=x-x%3+2;i++)
    {
        for(int j=y-y%3;j<=y-y%3+2;j++)
        {
            if(arr[i][j]==num) return false;
        }
    }
    return true;
}
void sudoku(int x,int y)
{
    if(y==9) sudoku(x+1,0);
    else if(x==9)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }
    else if(arr[x][y]==0)
    {
        for(int i=1;i<=9;i++)
        {
            if(check(x,y,i))
            {
                arr[x][y] = i;
                sudoku(x,y+1);
                arr[x][y] = 0;
            }
        }
    }
    else sudoku(x,y+1);
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin >> arr[i][j];
        }
    }
    sudoku(0,0);
    return 0;
}