#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

struct Trie {
	unordered_map<char, Trie*> kids;
};

ll h, w, n, res = 0;
vector<string> grid;
vector<vi> vis;
vi dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};

void dfs(ll r, ll c, Trie *t, ll d) {
	if (d >= 10) return;
	if (r < 0 || r >= h || c < 0 || c >= w) return;
	if (vis[r][c]) return;
	vis[r][c] = true;
	char ch = grid[r][c];
	if (!(t->kids.count(ch))) t->kids[ch] = new Trie();
	rep(i, 0, 4) dfs(r+dx[i], c+dy[i], t->kids[ch], d+1);
	vis[r][c] = false;
}

bool trie_has(string& s, Trie *t) {
	for (char c : s) {
		if (!(t->kids.count(c))) return false;
		t = t->kids[c];
	}
	return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> h >> w;
	grid.assign(h, "");
	rep(i, 0, h) cin >> grid[i];
	vis.assign(h, vi(w, 0));
	Trie *t = new Trie();
	rep(i, 0, h) rep(j, 0, w) dfs(i, j, t, 0);
	cin >> n;
	ll res = 0;
	while (n--) {
		string s; cin >> s;
		res += trie_has(s, t);
	}
	printf("%lld\n", res);
}
