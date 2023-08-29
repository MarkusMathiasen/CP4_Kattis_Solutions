#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T, n;
vector<string> M;
string D, X;
map<char, char> enc, deco;
vi matches;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n;
		M.assign(n, "");
		rep(i, 0, n) cin >> M[i];
		cin >> D >> X;
		matches.clear();
		rep(i, 0, n) {
			if (sz(M[i]) != sz(D)) continue;
			enc.clear();
			deco.clear();
			bool match = true;
			rep(j, 0, sz(D))
				if ((deco.count(M[i][j]) && deco[M[i][j]] != D[j]) 
					|| (enc.count(D[j]) && enc[D[j]] != M[i][j])) {
					match = false;
					break;
				} else
					enc[D[j]] = M[i][j],
					deco[M[i][j]] = D[j];
			if (match) matches.push_back(i);
		}
		if (!sz(matches)) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		enc.clear();
		deco.clear();
		rep(i, 0, sz(D)) {
			bool certain = true;
			for (ll idx : matches)
				certain &= M[idx][i] == M[matches[0]][i];
			if (certain)
				deco[M[matches[0]][i]] = D[i];
		}
		if (sz(deco) == 25) {
			set<char> keys, values;
			for (auto [k,v] : deco)
				keys.insert(k),
				values.insert(v);
			char k = ' ', v = ' ';
			for (char c = 'a'; c <= 'z'; c++) {
				if (!keys.count(c)) k = c;
				if (!values.count(c)) v = c;
			}
			deco[k] = v;
		}
		for (char c : X)
			printf("%c", deco.count(c) ? deco[c] : '?');
		printf("\n");
	}
}
