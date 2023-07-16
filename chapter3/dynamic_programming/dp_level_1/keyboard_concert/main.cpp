#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
vector<unordered_set<int>> keys;

int main() {
	// Read input
	scanf("%d%d", &n, &m);
	keys.assign(n, unordered_set<int>());
	rep(i, 0, n) {
		int k; scanf("%d", &k);
		rep(j, 0, k) {
			int x; scanf("%d", &x);
			keys[i].insert(x);
		}
	}
	// Algorithm
	set<int> boards;
	rep(i, 0, n) boards.insert(i);
	int res = 0;
	rep(i, 0, m) {
		int key; scanf("%d", &key);
no_read:
		vector<int> rem;
		for (int board : boards)
			if (!keys[board].count(key))
				rem.push_back(board);
		for (int r : rem)
			boards.erase(r);
		if (boards.empty()) {
			rep(i, 0, n) boards.insert(i);
			res++;
			goto no_read;
		}
	}
	printf("%d\n", res);
}
