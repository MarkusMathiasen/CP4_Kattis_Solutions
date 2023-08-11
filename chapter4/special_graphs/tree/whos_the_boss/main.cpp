#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct person {
	int id, sal, h;
};

int n, q;
vector<person> A;
unordered_map<int, int> toi;
vi sub, post_min, p;
vector<vi> tree;

void dfs(int v) {
	sub[v] = 1;
	for (int u : tree[v]) {
		if (sub[u]) continue;
		dfs(u);
		sub[v] += sub[u];
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> q;
	A.assign(n, person());
	rep(i, 0, n) cin >> A[i].id >> A[i].sal >> A[i].h;
	sort(all(A), [](const person& a, const person& b) {
		if (a.h != b.h)
			return a.h < b.h;
		return a.sal < b.sal;
	});
	rep(i, 0, n) toi[A[i].id] = i;
	tree.assign(n, {});
	p.assign(n, 0);
	set<pii> seen;
	seen.insert({A[n-1].sal, n-1});
	for (int i = n-2; i >= 0; i--) {
		auto [s, lowest] = *seen.upper_bound({A[i].sal, -1});
		p[i] = A[lowest].id;
		tree[lowest].push_back(i);
		seen.insert({A[i].sal, i});
	}
	sub.assign(n, 0);
	dfs(n-1);
	while (q--) {
		int id; cin >> id;
		printf("%d %d\n", p[toi[id]], sub[toi[id]]-1);
	}
}
