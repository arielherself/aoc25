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

	while (true) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (a[i][j] != '@') {
					continue;
				}

				int cnt = 0;
				if (i > 0 and a[i - 1][j] == '@') {
					cnt += 1;
				}
				if (i > 0 and j + 1 < m and a[i - 1][j + 1] == '@') {
					cnt += 1;
				}
				if (j + 1 < m and a[i][j + 1] == '@') {
					cnt += 1;
				}
				if (i + 1 < n and j + 1 < m and a[i + 1][j + 1] == '@') {
					cnt += 1;
				}
				if (i + 1 < n and a[i + 1][j] == '@') {
					cnt += 1;
				}
				if (i + 1 < n and j > 0 and a[i + 1][j - 1] == '@') {
					cnt += 1;
				}
				if (j > 0 and a[i][j - 1] == '@') {
					cnt += 1;
				}
				if (i > 0 and j > 0 and a[i - 1][j - 1] == '@') {
					cnt += 1;
				}

				if (cnt < 4) {
					res += 1;
					a[i][j] = '.';
					goto fi;
				}
			}
		}
		break;
	fi:
		;;
	}

	cout << res << endl;
}
