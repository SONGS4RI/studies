#include <iostream>
using namespace std;
int GCD(int A, int R)
{
	return R ? GCD(R, A % R) : A;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b;
	cin >> a >> b;
	int gcd = GCD(a, b);
	cout << gcd << '\n' << gcd * (a / gcd) * (b / gcd);
    return 0;
}

