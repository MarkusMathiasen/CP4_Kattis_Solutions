#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, q;
vi nxt, dist, fin, start, deg;

void dfs(int v) {
	if (dist[v] != -1) return;
	if (nxt[v] == -1) {
		dist[v] = 0;
		fin[v] = v;
	} else {
		dfs(nxt[v]);
		dist[v] = dist[nxt[v]]+1;
		fin[v] = fin[nxt[v]];
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	nxt.assign(n, 0);
	deg.assign(n, 0);
	rep(i, 0, n) {
		cin >> nxt[i];
		if (nxt[i] != -1)
			deg[nxt[i]]++;
	}
	dist.assign(n, -1);
	fin.assign(n, -1);
	rep(i, 0, n) dfs(i);
	start.assign(n, -1);
	rep(i, 0, n)
		if (!deg[i]) {
			int& s = start[fin[i]];
			if (s == -1 || dist[s] > dist[i])
				s = i;
		}
	cin >> q;
	while (q--) {
		int x; cin >> x;
		printf("%d\n", start[fin[x]]);
	}
}
