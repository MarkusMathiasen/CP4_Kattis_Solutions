#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int T, n;
vector<vi> dist;
vector<pii> A;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n; n+=2;
		A.assign(n, {0, 0});
		rep(i, 0, n) cin >> A[i].first >> A[i].second;
		dist.assign(n, vi(n, 1e9));
		rep(i, 0, n) rep(j, i+1, n)
			dist[i][j] = dist[j][i] = abs(A[i].first-A[j].first)+abs(A[i].second-A[j].second);
		rep(k, 0, n) rep(i, 0, n) rep(j, 0, n)
			dist[i][j] = min(dist[i][j], max(dist[i][k],dist[k][j]));
		if (dist[0][n-1] <= 1000) printf("happy\n");
		else printf("sad\n");
	}
}
