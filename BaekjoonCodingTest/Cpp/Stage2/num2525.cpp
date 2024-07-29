#include<iostream>
using namespace std;
int main()
{
    int h,m,t;
    cin >> h >> m >> t;

    cout << (h+(t+m)/60)%24 << " " << (t+m)%60;
    
    return 0;
}