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
	vector<int> xs, ys;
	while (cin >> buf) {
		int p = find(buf.begin(), buf.end(), ',') - buf.begin();
		int x = stoi(buf.substr(0, p));
		int y = stoi(buf.substr(p + 1));
		a.emplace_back(x, y);
		xs.emplace_back(x);
		xs.emplace_back(x + 1);
		xs.emplace_back(x - 1);
		ys.emplace_back(y);
		ys.emplace_back(y + 1);
		ys.emplace_back(y - 1);
	}

	int n = a.size();
	cerr << n << endl;
	
	sort(xs.begin(), xs.end());
	int m = unique(xs.begin(), xs.end()) - xs.begin();
	xs.resize(m);
	auto gx = [&] (int x) { return lower_bound(xs.begin(), xs.end(), x) - xs.begin(); };

	sort(ys.begin(), ys.end());
	int k = unique(ys.begin(), ys.end()) - ys.begin();
	ys.resize(k);
	auto gy = [&] (int y) { return lower_bound(ys.begin(), ys.end(), y) - ys.begin(); };

	vector grid(m, vector<int>(k, 0));
	for (int i = 0; i < n; ++i) {
		auto [x1, y1] = a[i];
		auto [x2, y2] = a[(i + 1) % n];
		x1 = gx(x1);
		x2 = gx(x2);
		y1 = gy(y1);
		y2 = gy(y2);
		if (x1 == x2) {
			if (y1 > y2) {
				swap(y1, y2);
			}
			for (int y = y1; y <= y2; ++y) {
				grid[x1][y] = 2;
			}
		} else {
			if (x1 > x2) {
				swap(x1, x2);
			}
			for (int x = x1; x <= x2; ++x) {
				grid[x][y1] = 2;
			}
		}
	}

	int bad = 0;
	auto dfs = [&] (auto&& dfs, int x, int y) -> void {
		if (x < 0 or x >= m or y < 0 or y >= k) {
			bad = 1;
			return;
		}
		if (grid[x][y] != 0) {
			return;
		}
		grid[x][y] = 1;
		dfs(dfs, x - 1, y);
		dfs(dfs, x + 1, y);
		dfs(dfs, x, y - 1);
		dfs(dfs, x, y + 1);
	};

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < k; ++j) {
			if (grid[i][j] == 0) {
				dfs(dfs, i, j);
				goto fi;
			}
		}
	}
	__builtin_trap();
fi:
	;;

	vector ps(m + 1, vector<int>(k + 1));
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= k; ++j) {
			ps[i][j] = int(grid[i - 1][j - 1] == bad) + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
		}
	}

	ll res = 0;
	for (int i = 0; i < n; ++i) {
		auto [x1, y1] = a[i];
		for (int j = i + 1; j < n; ++j) {
			auto [x2, y2] = a[j];
			int x11 = gx(x1);
			int y11 = gy(y1);
			int x21 = gx(x2);
			int y21 = gy(y2);
			if (x11 > x21) {
				swap(x11, x21);
			}
			if (y11 > y21) {
				swap(y11, y21);
			}
			int c = ps[x21 + 1][y21 + 1] - ps[x21 + 1][y11] - ps[x11][y21 + 1] + ps[x11][y11];
			assert(c >= 0);
			if (c == 0) {
				ll curr = ll(abs(a[i].x - a[j].x) + 1) * (abs(a[i].y - a[j].y) + 1);
				res = max(res, curr);
			}
		}
	}

	cout << res << endl;
}
