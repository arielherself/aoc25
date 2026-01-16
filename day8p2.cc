#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct quick_union {
	vector<int> c;
	vector<int> sz;
	quick_union() = delete;
	explicit quick_union(int n) : c(n), sz(n) {
		for (int i = 0; i < n; ++i) {
			c[i] = i;
			sz[i] = 1;
		}
	}
	inline int query(int i) {
		while (i != c[i]) {
			i = c[i] = c[c[i]];
		}
		return i;
	}
	inline void merge(int i, int j) {
		if (query(i) == query(j)) {
			return;
		}
		sz[query(i)] += sz[query(j)];
		c[query(j)] = query(i);
	}
	inline int query_size(int i) {
		return sz[query(i)];
	}
};

struct point {
	int x, y, z;
};

[[gnu::always_inline]]
inline ll distance(const point& a, const point& b) {
	return ll(a.x - b.x) * (a.x - b.x) + ll(a.y - b.y) * (a.y - b.y) + ll(a.z - b.z) * (a.z - b.z);
}

int main() {
	vector<point> a;
	string buf;
	while (cin >> buf) {
		int p1 = find(buf.begin(), buf.end(), ',') - buf.begin();
		int p2 = find(buf.begin() + p1 + 1, buf.end(), ',') - buf.begin();
		int x = stoi(buf.substr(0, p1));
		int y = stoi(buf.substr(p1 + 1, p2 - p1 - 1));
		int z = stoi(buf.substr(p2 + 1));
		cerr << x << ' ' << y << ' ' << z << endl;
		a.push_back({x, y, z});
	}

	int n = a.size();

	vector<pair<int, int>> ops;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			ops.emplace_back(i, j);
		}
	}

	sort(ops.begin(), ops.end(), [&] (const pair<int, int>& p, const pair<int, int>& q) {
		return distance(a[p.first], a[p.second]) < distance(a[q.first], a[q.second]);
	});

	quick_union qu(n);

	int last_i, last_j;
	int blocks = n;
	for (auto&& [i, j] : ops) {
		if (qu.query(i) != qu.query(j)) {
			blocks -= 1;
			qu.merge(i, j);
			if (blocks == 1) {
				last_i = i;
				last_j = j;
			}
		}
	}

	cout << ll(1) * a[last_i].x * a[last_j].x << endl;
}
