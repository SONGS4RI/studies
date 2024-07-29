#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double r;
    cout << fixed;
    cout.precision(6);
    cin >> r;
    cout << M_PI*pow(r,2) << "\n";
    cout << pow(r,2)*2;
    return 0;
}