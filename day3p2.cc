#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ll res = 0;
	string s;
	while (cin >> s) {
		int n = s.size();

		int last = -1;
		ll curr = 0;
		for (int i = 0; i < 12; ++i) {
			int k = last + 1;
			for (int j = last + 2; j < n - 11 + i; ++j) {
				if (s[j] > s[k]) {
					k = j;
				}
			}
			last = k;
			curr = curr * 10 + int(s[k] - '0');
		}

		res += curr;
	}
	cout << res << endl;
}
