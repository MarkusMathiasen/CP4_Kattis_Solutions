#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

int T, N;
vi uf, siz;
vector<tuple<int,int,int>> edges;

ll find(ll v) {
	if (uf[v] == v) return v;
	return uf[v] = find(uf[v]);
}
bool issame(int a, int b) {return find(a) == find(b);}
void same(int a, int b) {
	ll x = find(a), y = find(b);
	if (x == y) return;
	siz[y] += siz[x];
	uf[x] = y;
}
ll get_size(int v) {return siz[find(v)];}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		uf.assign(N, 0);
		rep(i, 1, N) uf[i] = i;
		siz.assign(N, 1);
		edges.clear();
		rep(i, 1, N) {
			int a, b, w; scanf("%d%d%d", &a, &b, &w); a--; b--;
			edges.push_back({w, a, b});
		}
		sort(all(edges));
		ll res = 0;
		for (auto [w, a, b] : edges) {
			if (issame(a, b)) continue;
			res += get_size(a)*get_size(b)*(w+1)-1;
			same(a, b);
		}
		printf("%lld\n", res);
	}
}
