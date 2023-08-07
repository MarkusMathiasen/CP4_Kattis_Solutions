#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, Q, is[500][500], has[500][500];
unordered_map<string, int> toi;

int read_name(string& s) {
	if (!toi.count(s))
		toi[s] = sz(toi),
		n++;
	return toi[s];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> m >> Q;
	rep(i, 0, m) {
		string a, op, b; cin >> a >> op >> b;
		int x = read_name(a), y = read_name(b);
		if (op == "is-a") is[x][y] = 1;
		else if (op == "has-a") has[x][y] = 1;
		else assert(false);
	}
	rep(i, 0, n) is[i][i] = 1;
	rep(k, 0, n) rep(i, 0, n) rep(j, 0, n)
		is[i][j] |= is[i][k] & is[k][j];
	rep(k, 0, n) rep(i, 0, n) rep(j, 0, n) {
		has[i][j] |= has[i][k] & (is[k][j] | has[k][j]);
		has[i][j] |= is[i][k] & has[k][j];
	}
	rep(q, 1, Q+1) {
		printf("Query %d: ", q);
		string a, op, b; cin >> a >> op >> b;
		int x = toi[a], y = toi[b];
		if (op == "is-a") printf(is[x][y] ? "true\n" : "false\n");
		else if (op == "has-a") printf(has[x][y] ? "true\n" : "false\n");
		else assert(false);
	}
}
