#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct point {
	int x, y;
	point() = delete;
	point(int x, int y) : x(x), y(y) {}
};

int main() {
	string buf;
	vector<point> a;
	while (cin >> buf) {
		int p = find(buf.begin(), buf.end(), ',') - buf.begin();
		int x = stoi(buf.substr(0, p));
		int y = stoi(buf.substr(p + 1));
		a.emplace_back(x, y);
	}

	int n = a.size();
	cerr << n << endl;
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			ll curr = ll(abs(a[i].x - a[j].x) + 1) * (abs(a[i].y - a[j].y) + 1);
			res = max(res, curr);
		}
	}

	cout << res << endl;
}
