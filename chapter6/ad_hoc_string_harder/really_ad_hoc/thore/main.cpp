#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

string name = "ThoreHusfeldt";

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n; cin >> n;
	ll pre = 0;
	rep(i, 0, n) {
		string s; cin >> s;
		if (s == name) break;
		while (pre <= sz(s) && s.substr(0, pre) == name.substr(0, pre))
			pre++;
	}
	if (pre == 0) printf("Thore is awesome\n");
	else if (pre >= sz(name)) printf("Thore sucks\n");
	else printf("%s\n", name.substr(0, pre).c_str());
}
