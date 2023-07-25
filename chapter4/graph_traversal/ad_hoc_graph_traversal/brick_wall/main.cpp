#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N, c1, c2, c3, L;
vi b;
set<int> sums;
set<tuple<int, int, int, int>> dp;

bool dfs(int l, int c1, int c2, int c3) {
	if (dp.count({l, c1, c2, c3})) return false;
	dp.insert({l, c1, c2, c3});
	if (sums.count(l)) return false;
	if (l > L) return false;
	if (l == L) return true;
	bool res = false;
	if (c1) res |= dfs(l+1, c1-1, c2, c3);
	if (c2) res |= dfs(l+2, c1, c2-1, c3);
	if (c3) res |= dfs(l+3, c1, c2, c3-1);
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> c1 >> c2 >> c3;
	b.assign(N, 0);
	rep(i, 0, N) cin >> b[i];
	int sum = 0;
	rep(i, 0, sz(b)-1)
		sum += b[i], sums.insert(sum);
	L = sum+b.back();
	bool res = dfs(0, c1, c2, c3);
	printf(res ? "YES\n" : "NO\n");
}
