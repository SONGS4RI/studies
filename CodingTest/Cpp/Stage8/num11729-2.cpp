#include<iostream>
#include<cmath>
using namespace std;
void hanoi(int n,int left,int right,int mid)
{
    if(n==1) cout << left << " " << right << "\n";
    else
    {
        hanoi(n-1,left,mid,right);
        cout << left << " " << right << "\n";
        hanoi(n-1,mid,right,left);
    }
}
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n;
    cin >> n;
    cout << (int)pow(2,n)-1 << "\n";
    hanoi(n,1,3,2);
    return 0;
}