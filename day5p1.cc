#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	string buf;
	vector<pair<ll, ll>> range;
	vector<ll> queries;
	while (cin >> buf) {
		int pos = find(buf.begin(), buf.end(), '-') - buf.begin();
		if (pos != buf.length()) {
			ll l = stoll(buf.substr(0, pos));
			ll r = stoll(buf.substr(pos + 1));
			range.emplace_back(l, r);
		} else {
			queries.emplace_back(stoll(buf));
		}
	}

	int res = 0;
	for (auto&& x : queries) {
		for (auto&& [l, r] : range) {
			if (l <= x and x <= r) {
				res += 1;
				break;
			}
		}
	}

	cout << res << endl;
}
