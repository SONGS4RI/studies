#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int t,x1,x2,y1,y2,r1,r2,temp;
    double d;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        if(r1>r2)
        {
            temp = x2;
            x2 = x1;
            x1 = temp;
            temp = y2;\
            y2 = y1;
            y1 = temp;
            temp = r2;
            r2 = r1;
            r1 = temp;
        }
        d = sqrt(pow(abs(x1-x2),2)+pow(abs(y1-y2),2));
        if(d==0&&r1==r2)cout << -1 << "\n";
        else if(d>r1+r2 || d+r1<r2) cout << 0 << "\n";
        else if(d==r1+r2 || r2==d+r1) cout << 1 << "\n";
        else cout << 2 << "\n";
    }
    return 0;
}