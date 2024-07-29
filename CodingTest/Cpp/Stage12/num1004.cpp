#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int t,x1,y1,x2,y2,n,cx,cy,r;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int cnt = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> n;
        for(int j=0;j<n;j++)
        {
            cin >> cx >> cy >> r;
            double d1 = sqrt(pow(cx-x1,2)+pow(cy-y1,2));
            double d2 = sqrt(pow(cx-x2,2)+pow(cy-y2,2));
            if(d1>r && d2<r) cnt++;
            else if(d1<r && d2>r) cnt++;            
        }
        cout << cnt << "\n";
    }
    return 0;
}