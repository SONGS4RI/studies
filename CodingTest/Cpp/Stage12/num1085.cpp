#include<iostream>
using namespace std;
int main()
{
    int x,y,w,h,x_min,y_min;
    cin >> x >> y >> w >> h;
    if(w-x>x) x_min = x;
    else x_min = w-x;
    if(h-y>y) y_min = y;
    else y_min = h-y;
    if(x_min>y_min) cout << y_min;
    else cout << x_min;

    return 0;
}
