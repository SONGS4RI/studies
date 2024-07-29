#include<iostream>
using namespace std;
int main()
{
    int n=0, sum=0, num;
    cin >> n >> num;
    while(num>0)
    {
        sum += num%10;
        num/=10;
    }
    cout << sum;
    
    return 0;
}