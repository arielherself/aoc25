#include <bits/stdc++.h>
using namespace std;

int main() {
	int res = 0;
	string s;
	while (cin >> s) {
		int n = s.size();
		int j = 0;
		for (int i = 1; i < n - 1; ++i) {
			if (s[i] > s[j]) {
				j = i;
			}
		}
		int l = j + 1;
		for (int i = j + 2; i < n; ++i) {
			if (s[i] > s[l]) {
				l = i;
			}
		}
		res += int(s[j] - '0') * 10 + int(s[l] - '0');
	}
	cout << res << endl;
}
