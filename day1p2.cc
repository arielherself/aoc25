#include <bits/stdc++.h>
using namespace std;


constexpr int TOTAL = 100;

int main() {
	int loc = 50;
	int result = 0;
	string op;
	while (cin >> op) {
		bool sgn = op[0] == 'R';
		int num = stoi(op.substr(1));

		if (sgn) {
			int left = TOTAL - loc;
			result += max(0, num + TOTAL - left) / TOTAL;
			loc = (loc + num) % TOTAL;
		} else {
			if (loc == 0) {
				result -= 1;
			}
			int left = loc;
			result += max(0, num + TOTAL - left) / TOTAL;
			loc = ((loc - num) % TOTAL + TOTAL) % TOTAL;
		}
		// if (loc == 0) {
		// 	result += 1;
		// }
	}

	cout << result << endl;

	return 0;
}
