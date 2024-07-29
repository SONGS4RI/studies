#include<iostream>
using namespace std;
int self(int n)
{
    int num =n;
    while(n>0)
    {
        num += n%10;
        n/=10;
    }
    return num;
}
int main()
{
    int arr[10024] = {0,};
    for(int i=1; i<=9993;i++)
    {
        arr[self(i)] =1;
    }
    for(int i=1; i<=10000; i++)
    {
        if(arr[i]==0) cout << i << "\n";
    }
    return 0;
}