#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	vector<int> operands;
	vector<char> operators;
	string buf;
	while (cin >> buf) {
		if (isalnum(buf[0]) != 0) {
			operands.emplace_back(stoi(buf));
		} else {
			operators.emplace_back(buf[0]);
		}
	}
	int n = operators.size();
	int m = operands.size() / n;


	ll res = 0;

	for (int i = 0; i < n; ++i) {
		cout << operators[i] << ' ';
		if (operators[i] == '+') {
			ll curr = 0;
			for (int j = 0; j < m; ++j) {
				curr += operands[j * n + i];
			}
			res += curr;
			cout << curr << endl;
		} else {
			ll curr = 1;
			for (int j = 0; j < m; ++j) {
				curr *= operands[j * n + i];
			}
			res += curr;
			cout << curr << endl;
		}
	}
	cout << res << endl;
}
