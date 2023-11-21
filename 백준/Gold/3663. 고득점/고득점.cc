#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		int answer = 0, move = INT32_MAX, size = s.size();
		for (int i = 0; i < size; i++) {
			answer += min(s[i] - 'A', 'Z' - s[i] + 1);
			if (s[i] != 'A') s[i] = 'B';
		}

		for (int i = 0, j; i < size; i++) {
			j = find(s.begin() + i + 1, s.end(), 'B') - s.begin();
			int right = i * 2 + size - j;
			int left = i + (size - j) * 2;
			move = min(move, min(left, right));
		}
		cout << answer + move << "\n";
	}
}