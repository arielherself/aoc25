#include <bits/stdc++.h>
using namespace std;

int parse_state(const string& s) {
	int n = s.size();
	int res = 0;
	for (int i = 1; i < n - 1; ++i) {
		if (s[i] == '#') {
			res |= 1 << i - 1;
		}
	}
	return res;
}

int parse_button(const string& s) {
	int n = s.size();
	int curr = 0;
	int res = 0;
	for (int i = 1; i < n - 1; ++i) {
		if (s[i] == ',') {
			res |= 1 << curr;
			curr = 0;
		} else {
			curr = curr * 10 + int(s[i] - '0');
		}
	}
	return res | 1 << curr;
}

int main() {
	string buf;
	int target;
	vector<int> choices;
	int res = 0;
	while (cin >> buf) {
		if (buf[0] == '[') {
			target = parse_state(buf);
		} else if (buf[0] == '(') {
			choices.emplace_back(parse_button(buf));
		} else {
			// evaluate
			int m = choices.size();
			int mn = INT_MAX;
			for (int i = 0; i < (1 << m); ++i) {
				int curr = 0;
				int cnt = 0;
				for (int j = 0; j < m; ++j) {
					if (i >> j & 1) {
						curr ^= choices[j];
						cnt += 1;
					}
				}
				if (curr == target) {
					mn = min(mn, cnt);
				}
			}
			cerr << mn << endl;
			res += mn;
			choices = {};
		}
	}
	cout << res << endl;
}
