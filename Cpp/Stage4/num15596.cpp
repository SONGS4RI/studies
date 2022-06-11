#include<iostream>
#include<vector>
using namespace std;
long long sum(vector<int> &a)
{
    long long res =0;
    for(int i=0; i<a.size(); i++) res += a[i];
    return res;
}
