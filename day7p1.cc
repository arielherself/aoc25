#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<string> a;
	string buf;
	while (cin >> buf) {
		a.emplace_back(buf);
	}
	int n = a.size();
	int m = a[0].size();
	cerr << n << ' ' << m << endl;
	int res = 0;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 'S' or a[i][j] == '|') {
				if (a[i + 1][j] == '^') {
					res += 1;
					assert(j > 0 and j + 1 < m and a[i + 1][j - 1] != '^' and a[i + 1][j + 1] != '^');
					a[i + 1][j - 1] = a[i + 1][j + 1] = '|';
				} else {
					a[i + 1][j] = '|';
				}
			}
		}
	}
	cout << res << endl;
}
