#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int,int>> A(n);
	vector<int> res(n);
	for (int i=0; i<n; i++) {
		cin >> A[i].first;
		A[i].second = i;
	}
	sort(A.begin(), A.end());
	for (int i=0; i<n; i++) {
		res[A[i].second] = i;
	}
	for (auto r : res) cout << r << " ";
}