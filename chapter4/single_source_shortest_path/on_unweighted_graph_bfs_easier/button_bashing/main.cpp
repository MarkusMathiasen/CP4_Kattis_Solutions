#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, t; scanf("%d%d", &n, &t);
		vi but(n, 0);
		rep(i, 0, n) scanf("%d", &but[i]);
		vi dist(3601, -1);
		queue<pii> q;
		q.push({0, 0});
		while (!q.empty()) {
			auto [v,d] = q.front(); q.pop();
			if (dist[v] != -1) continue;
			dist[v] = d;
			for (int b : but)
				q.push({max(0, min(3600, v+b)), d+1});
		}
		int extra, presses;
		rep(i, t, 3601)
			if (dist[i] != -1) {
				extra = i-t;
				presses = dist[i];
				break;
			}
		printf("%d %d\n", presses, extra);
	}
}
