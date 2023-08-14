#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll b, mod;
string p, m;

ll b10(string x) {
	ll res = 0;
	ll k = 1;
	for (int i = sz(x)-1; i >= 0; i--) {
		res = (res+(x[i]-'0')*k)%mod;
		k = (k*b)%mod;
	}
	return res;
}
ll bb(ll x) {
	ll res = 0;
	ll k = 1;
	while (x) {
		res += (x%b)*k;
		x /= b;
		k *= 10;
	}
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> b >> p >> m) {
		mod = 1e18;
		mod = b10(m);
		ll res = b10(p);
		printf("%lld\n", bb(res));
	}
}
