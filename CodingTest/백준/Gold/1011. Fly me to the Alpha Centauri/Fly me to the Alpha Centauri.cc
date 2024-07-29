#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
0 1 2 3 3 4 4 5 5 5 6 6 6 7 7 7 7 8 8 8 8
idx: 0 1 2 3 4 5  6  7  8  9 10
res: 0 1 2 4 6 9 12 16 20 25 30 ....
*/
int main() {
	int t, x, y;
	vector<long long> dp(92682, 0);
	for (int i=1; i<92681; i++) {
		if (i%2) {// odd
			dp[i] = 1LL*(i+1)*(i+1)/4;
		} else {// even
			dp[i] = dp[i-1] + (i+1)/2;
		}
	}
	dp.back() = INT32_MAX;
	vector<int> res;
	cin >> t;
	while (t--) {
		cin >> x >> y;
		y -= x+1;
		res.push_back(upper_bound(dp.begin(), dp.end(), y) - dp.begin());
	}
	for (auto& r : res) {
		cout << r << "\n";
	}
}