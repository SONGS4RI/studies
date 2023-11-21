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
		}

		for (int i = 0, j; i < size; i++) {
			for (j = i + 1; j < size && s[j] == 'A'; j++);
			if (s[i] == 'A' && j == size + 1) break;
			int right = i * 2 + size - j;
			int left = i + (size - j) * 2;
			move = min(move, min(left, right));
		}
		cout << answer + move << "\n";
	}
}