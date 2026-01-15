#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	string buf;
	vector<pair<ll, ll>> range;
	// vector<ll> queries;
	while (cin >> buf) {
		int pos = find(buf.begin(), buf.end(), '-') - buf.begin();
		if (pos != buf.length()) {
			ll l = stoll(buf.substr(0, pos));
			ll r = stoll(buf.substr(pos + 1));
			range.emplace_back(l, r);
		// } else {
		// 	queries.emplace_back(stoll(buf));
		}
	}

	sort(range.begin(), range.end());
	ll last_r = -1;
	ll res = 0;
	for (auto&& [l, r] : range) {
		last_r = max(last_r, l - 1);
		res += max<ll>(0, r - last_r);
		last_r = max(last_r, r);
	}
	cout << res << endl;
}
