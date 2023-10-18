#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
	vector<string> reg;
	stringstream ss(s);
	string s2;
	while (getline(ss, s2, '*'))
		reg.push_back(s2);
	if (s.back() == '*')
		reg.push_back("");
    ll n; cin >> n;
    while (n--) {
        cin >> s;
		ll pos = 0, i = 0;
		while (i < sz(reg)) {
			pos = s.find(reg[i], pos);
			if (pos == -1) break;
			pos += sz(reg[i++]);
		}
		bool res = pos != -1;
		res &= reg[0] == "" || (sz(reg[0]) <= sz(s) && s.substr(0, sz(reg[0])) == reg[0]);
		res &= reg.back() == "" || (sz(reg.back()) <= sz(s) && s.substr(sz(s)-sz(reg.back())) == reg.back());
		if (sz(reg) == 1) res = reg[0] == s;
		if (res) printf("%s\n", s.c_str());
    }
}
