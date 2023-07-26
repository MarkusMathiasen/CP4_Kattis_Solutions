#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int T;
int S, N, uf[500];
pii A[500];
tuple<float, int, int> edges[500*500];

double dist(int a, int b) {
	return hypot(A[a].first-A[b].first, A[a].second-A[b].second);
}

int find(int v) {
	if (uf[v] == v) return v;
	return uf[v] = find(uf[v]);
}
bool issame(int a, int b) {return find(a) == find(b);}
void same(int a, int b) {uf[find(a)] = find(b);}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &S, &N);
		rep(i, 0, N) scanf("%d%d", &A[i].first, &A[i].second);
		int cnt = 0;
		rep(i, 0, N) rep(j, i+1, N)
			edges[cnt++] = {dist(i, j), i, j};
		rep(i, 0, N) uf[i] = i;
		sort(edges, edges+cnt);
		int comps = N;
		float res = 0;
		for (auto& [w,a,b] : edges) {
			if (issame(a,b)) continue;
			same(a,b);
			comps--;
			res = max(res, w);
			if (comps == S) break;
		}
		printf("%.2f\n", res);
	}
}
