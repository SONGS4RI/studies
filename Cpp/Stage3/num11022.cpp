#include<iostream>
using namespace std;
int main()
{
    int n,q,w;
    cin >> n;
    for(int i=1; i<n+1;i++)
    {
        cin >> q >> w;
        cout << "Case #" << i << ": " << q<<" + "<< w <<" = "<<q+w << "\n";
    }
    return 0;
}