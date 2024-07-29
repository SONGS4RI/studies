#include <iostream>
using namespace std;

pair<long long, long long> two_five_count(long long x)
{
    long long two_cnt = 0;
    long long five_cnt = 0;

    for(long long i=2; i<=x; i*=2)
    {
        two_cnt += x / i;
    }

    for(long long i=5; i<=x; i*=5)
    {
        five_cnt += x / i;
    }
    return make_pair(two_cnt, five_cnt);
}

int main()
{
    long long n, m;
    cin >> n >> m;

    pair<long long, long long> fc_n = two_five_count(n);
    pair<long long, long long> fc_nm = two_five_count(n-m);
    pair<long long, long long> fc_m = two_five_count(m);

    long long a = fc_n.first - (fc_nm.first + fc_m.first);
    long long b = fc_n.second - (fc_nm.second + fc_m.second);
    
    cout << ((a < b) ? a : b) << '\n';

    return 0;
}