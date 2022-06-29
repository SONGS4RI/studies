#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a,b,x[1001]={0,},y[1001]={0,};
    for(int i=0;i<3;i++)
    { 
       cin >> a >> b;
       x[a]++;
       y[b]++;
    }
    int* xp = find(x,x+1001,1);
    int* yp = find(y,y+1001,1);
    cout << xp-x << " " << yp-y;
    return 0;
}