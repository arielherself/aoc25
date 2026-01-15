#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	vector<string> a;
	string buf;
	while (cin >> buf) {
		a.emplace_back(buf);
	}
	int n = a.size();
	int m = a[0].size();
	cerr << n << ' ' << m << endl;

	vector dp(n, vector<ll>(m));
	for (int j = 0; j < m; ++j) {
		if (a[0][j] == 'S') {
			dp[0][j] = 1;
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i + 1][j] == '^') {
				assert(j > 0 and j + 1 < m and a[i + 1][j - 1] != '^' and a[i + 1][j + 1] != '^');
				dp[i + 1][j - 1] += dp[i][j];
				dp[i + 1][j + 1] += dp[i][j];
			} else {
				dp[i + 1][j] += dp[i][j];
			}
		}
	}

	cout << accumulate(dp[n - 1].begin(), dp[n - 1].end(), ll(0)) << endl;
}
