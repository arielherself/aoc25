#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	vector<string> inputs;
	string buf;
	vector<string> nodes;
	while (cin >> buf) {
		inputs.emplace_back(buf);
		if (buf.back() == ':') {
			nodes.emplace_back(buf.substr(0, buf.size() - 1));
		} else {
			nodes.emplace_back(buf);
		}
	}
	sort(nodes.begin(), nodes.end());
	int n = unique(nodes.begin(), nodes.end()) - nodes.begin();
	nodes.resize(n);

	vector<vector<int>> ch(n);
	int from;
	for (auto&& s : inputs) {
		if (s.back() == ':') {
			int mapped = find(nodes.begin(), nodes.end(), s.substr(0, s.size() - 1)) - nodes.begin();
			from = mapped;
		} else {
			int mapped = find(nodes.begin(), nodes.end(), s) - nodes.begin();
			ch[mapped].emplace_back(from);
		}
	}

	vector<int> ind(n);
	int start, end;
	int mid[2];
	for (int i = 0; i < n; ++i) {
		for (auto&& v : ch[i]) {
			ind[v] += 1;
		}
		if (nodes[i] == "svr") {
			end = i;
		} else if (nodes[i] == "out") {
			start = i;
		} else if (nodes[i] == "dac") {
			mid[0] = i;
		} else if (nodes[i] == "fft") {
			mid[1] = i;
		}
	}

	vector<int> q = { start };
	vector<array<ll, 4>> cnt(n);
	cnt[start][0b00] = 1;
	while (not q.empty()) {
		int v = q.back();
		q.pop_back();
		if (v == mid[0]) {
			cnt[v][0b01] += cnt[v][0b00];
			cnt[v][0b11] += cnt[v][0b10];
		} else if (v == mid[1]) {
			cnt[v][0b10] += cnt[v][0b00];
			cnt[v][0b11] += cnt[v][0b01];
		}
		for (auto&& u : ch[v]) {
			for (int i = 0; i < 4; ++i) {
				cnt[u][i] += cnt[v][i];
			}
			if (--ind[u] == 0) {
				q.emplace_back(u);
			}
		}
	}

	cout << cnt[end][0b11] << endl;
}
