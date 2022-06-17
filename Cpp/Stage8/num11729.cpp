#include<iostream>
#include<cmath>
using namespace std;
int hanoi(int n,int left, int right, int mid)
{
    if(n==1) cout << left << " " << right;
    else
    {
        hanoi(n-1,left,mid,right);
        cout << left << " " << right;
        hanoi(n-1,mid,right,left);
    }

}
int main()
{
    int n;
    cin >>n;
    cout << pow(2,n)-1 << "\n";
    hanoi(n,1,3,2);
    return 0;
}