#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
vector<vector<long double>> dist;
vector<pii> A;

long double euclid(int a, int b) {
	return hypot(A[a].first-A[b].first, A[a].second-A[b].second);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while ((cin >> n), n) {
		dist.assign(n, vector<long double>(n, 1e9));
		rep(i, 0, n) dist[i][i] = 0;
		A.assign(n, {0,0});
		rep(i, 0, n)
			cin >> A[i].first >> A[i].second;
		cin >> m;
		while (m--) {
			int a, b; cin >> a >> b;
			dist[a][b] = dist[b][a] = euclid(a, b);
		}
		rep(k, 0, n) rep(i, 0, n) rep(j, 0, n)
			dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
		pii best = {-1, -1};
		long double val = 0;
		rep(i, 0, n) rep(j, i+1, n) val += dist[i][j];
		long double orig = val;
		rep(a, 0, n) rep(b, a+1, n) {
			long double nval = 0, euc = euclid(a, b);
			rep(i, 0, n) rep(j, i+1, n)
				nval += min(dist[i][j], min(
					dist[i][a]+dist[b][j]+euc,
					dist[i][b]+dist[a][j]+euc));
			if (nval + 1e-6 < val) {
				val = nval;
				best = {a, b};
			}
		}
		if (best.first == -1)
			printf("no addition reduces %Lf\n", val);
		else
			printf("adding %d %d reduces %Lf to %Lf\n",
				best.first, best.second, orig, val);
	}
}
