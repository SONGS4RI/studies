#include <iostream>
using namespace std;

int arr[9][9];
bool promising(int x, int y, int a)
{	
	for(int i=0; i<9; i++)
    {
		if(arr[x][i]==a) return false;
		if(arr[i][y]==a) return false;
	}
	for(int i=(x/3)*3; i<(x/3)*3+3; i++)
    {
		for(int j=(y/3)*3; j<(y/3)*3+3; j++)
			if(arr[i][j]==a) return false;
	}
	return true;
}
void sudoku(int x, int y)
{
	if(x==9)
    {
		for(int i=0; i<9; i++)
        {
			for(int j=0; j<9; j++)
				cout << arr[i][j] << " ";
			cout << "\n";
		}
		exit(0);
	}
	if(y==9) sudoku(x+1, 0);
	if(arr[x][y]==0)
    {
		for(int i=1; i<=9; i++){
			if(promising(x, y, i))
            {
				arr[x][y]=i;
				sudoku(x, y+1);
				arr[x][y]=0; // here
			}
		}
	}
	else sudoku(x, y+1);
}



int main()
{
	for(int i=0; i<9; i++)
    {
		for(int j=0; j<9; j++)
			cin >> arr[i][j];
	}
	sudoku(0, 0);	
	return 0;
}