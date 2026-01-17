#include <bits/stdc++.h>
using namespace std;

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
	for (int i = 0; i < n; ++i) {
		for (auto&& v : ch[i]) {
			ind[v] += 1;
		}
		if (nodes[i] == "you") {
			end = i;
		} else if (nodes[i] == "out") {
			start = i;
		}
	}

	vector<int> q = { start };
	vector<int> cnt(n);
	cnt[start] = 1;
	while (not q.empty()) {
		int v = q.back();
		q.pop_back();
		for (auto&& u : ch[v]) {
			cnt[u] += cnt[v];
			if (--ind[u] == 0) {
				q.emplace_back(u);
			}
		}
	}

	cout << cnt[end] << endl;
}
