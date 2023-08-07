#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int T, F, E;
vi R, M;

int elevator_dist(int a, int b) {
	int fa = R[a], fb = R[b];
	int res = 1e9;
	while (fa < F && fb < F) {
		res = min(res, abs(fa-fb));
		if (fa < fb) fa += M[a];
		else fb += M[b];
	}
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> F >> E;
		R.assign(E, -1);
		M.assign(E, -1);
		rep(i, 0, E) cin >> R[i] >> M[i];
		vector<vi> edist(E, vi(E, -1));
		rep(i, 0, E) rep(j, i, E)
			edist[i][j] = edist[j][i] = elevator_dist(i, j);
		vi dist(E, -1);
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		rep(i, 0, E) pq.push({R[i], i});
		while (!pq.empty()) {
			auto [d,v] = pq.top(); pq.pop();
			if (dist[v] != -1) continue;
			dist[v] = d;
			rep(i, 0, E) pq.push({d+edist[v][i], i});
		}
		vector<pii> stops; // identify stops
		rep(i, 0, E) {
			int h = R[i];
			while (h < F) {
				stops.push_back({h, dist[i]});
				h += M[i];
			}
		}
		sort(all(stops));
		int pre_h = 0, pre_c = 0;
		int res_h = 0, res_c = 0;
		for (auto [h,c] : stops) {
			int x = (c-pre_c + h-pre_h)/2;
			int nh = pre_h+x;
			int nc = pre_c+x;
			if (nc > res_c) {
				res_c = nc;
				res_h = nh;
			}
			pre_h = h, pre_c = c;
		}
		int nc = pre_c + F-1-pre_h;
		if (nc > res_c) 
			res_c = nc,
			res_h = F-1;
		printf("%d %d\n", res_c, res_h);
	}
}
