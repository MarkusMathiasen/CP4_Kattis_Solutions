#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

string word, line, s;
vector<vector<string>> endings;
ll E;

bool suf(string& w, string& of) {
	return sz(w) <= sz(of) && w== of.substr(sz(of)-sz(w), sz(w));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> word >> E;
	getline(cin, line);
	endings.assign(E, {});
	vi cands(E, false);
	rep(i, 0, E) {
		getline(cin, line);
		stringstream ss(line);
		while (ss >> s) {
			endings[i].push_back(s);
			cands[i] |= suf(s, word);
		}
	}
	ll P; cin >> P;
	getline(cin, line);
	rep(i, 0, P) {
		getline(cin, line);
		bool res = false;
		rep(i, 0, E) if (cands[i]) {
			for (string& s : endings[i])
				res |= suf(s, line);
		}
		printf(res ? "YES\n" : "NO\n");
	}
}
