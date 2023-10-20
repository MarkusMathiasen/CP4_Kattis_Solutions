#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

struct Trie {
	bool word;
	unordered_map<char, Trie*> kids;
};

void add_word(string& s, Trie *t) {
	for (char c : s) {
		if (!(t->kids.count(c)))
			t->kids[c] = new Trie();
		t = t->kids[c];
	}
	t->word = true;
}

vector<vi> vis(4, vi(4, 0));
vector<string> grid(4, "");
vector<string> found;
string st;
vi dx = {-1, -1, -1, 0, 1, 1, 1, 0};
vi dy = {-1, 0, 1, 1, 1, 0, -1, -1};

void dfs(ll i, ll j, Trie *t) {
	if (i < 0 || i >= 4 || j < 0 || j >= 4) return;
	if (vis[i][j]) return;
	if (!(t->kids.count(grid[i][j]))) return;
	Trie *t2 = t->kids[grid[i][j]];
	st.push_back(grid[i][j]);
	if (t2->word) found.push_back(st);
	t2->word = false;
	vis[i][j] = true;
	rep(dir, 0, 8) {
		dfs(i+dx[dir], j+dy[dir], t2);
		if (sz(t2->kids) == 0) {
			delete t2;
			t->kids.erase(grid[i][j]);
			break;
		}
	}
	vis[i][j] = false;
	st.pop_back();
}

unordered_map<ll, ll> points = {
	{3, 1}, {4, 1}, {5, 2}, {6, 3}, {7, 5}, {8, 11}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll N, B; cin >> N;
	vector<string> dic;
	while (N--) {
		string s; cin >> s;
		dic.push_back(s);
	}
	cin >> B;
	Trie *t = new Trie();
	while (B--) {
		for (string& s : dic)
			add_word(s, t);
		found.clear();
		rep(i, 0, 4) cin >> grid[i];
		rep(i, 0, 4) rep(j, 0, 4) {
			dfs(i, j, t);
		}
		ll score = 0;
		for (string& s : found)
			score += points[sz(s)];
		sort(all(found), [](const string& a, const string& b) {
			return sz(a) != sz(b) ? sz(a) > sz(b) : a < b;
		});
		printf("%lld %s %lld\n", score, found[0].c_str(), sz(found));
	}
}
