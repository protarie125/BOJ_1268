#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	auto dat = vvi(n, vi(5));
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < 5; ++j) {
			cin >> dat[i][j];
		}
	}

	auto ans = int{ 0 };
	auto maxCt = int{ 0 };
	for (auto i = 0; i < n; ++i) {
		auto ct = int{ 0 };
		for (auto j = 0; j < n; ++j) {
			if (i == j) {
				continue;
			}

			for (auto k = 0; k < 5; ++k) {
				if (dat[i][k] == dat[j][k]) {
					++ct;
					break;
				}
			}
		}

		if (maxCt < ct) {
			maxCt = ct;
			ans = i + 1;
		}
	}

	if (0 == ans) {
		ans = 1;
	}

	cout << ans;

	return 0;
}