#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double w,h,x,y,p,px,py;
    int cnt=0;
    cin >> w >> h >> x >> y >> p;
    for(int i=0;i<p;i++)
    {
        cin >> px >> py;
        px = abs(px-x-w/2);
        py = abs(py-y-h/2);
        double d = sqrt(pow(px-w/2,2)+pow(py,2));
        if(px<=w/2 && py<=h/2) cnt++;
        else if(d<=h/2) cnt++;
    }
    cout << cnt;
    return 0;
}