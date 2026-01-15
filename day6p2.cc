#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	vector<string> lines;
	string buf;
	while (getline(cin, buf)) {
		lines.emplace_back(buf);
	}
	assert(lines[0].length() == lines[1].length());
	int n = lines[0].length();
	int m = lines.size() - 1;
	vector<int> operands;
	ll res = 0;
	auto calc = [&] (int i) {
		char operator_ = lines[m][i + 1];
		if (operator_ == '+') {
			ll curr = 0;
			for (auto&& x : operands) {
				curr += x;
			}
			res += curr;
		} else {
			ll curr = 1;
			for (auto&& x : operands) {
				curr *= x;
			}
			res += curr;
		}
		operands = {};
	};
	for (int i = n - 1; ~i; --i) {
		int curr = 0;
		bool flag = false;
		for (int j = 0; j < m; ++j) {
			if (lines[j][i] != ' ') {
				flag = true;
				curr = curr * 10 + (lines[j][i] - '0');
			}
		}
		if (not flag) {
			// evaluate
			calc(i);
		} else {
			operands.emplace_back(curr);
		}
	}
	calc(-1);
	cout << res << endl;
}
