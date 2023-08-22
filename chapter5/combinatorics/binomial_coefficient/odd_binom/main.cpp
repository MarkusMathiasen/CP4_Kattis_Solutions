#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n;

map<ll, ll> m;

ll a(ll n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (m.count(n)) return m[n];
	if (n%2 == 0) return m[n] = 3*a(n/2);
	return m[n] = 2*a(n/2) + a(n/2+1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	cout << a(n) << endl;
}
