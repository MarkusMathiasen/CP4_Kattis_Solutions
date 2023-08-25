#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T, k;
vi A;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> k;
		A.assign(k, 0);
		ll a = 1, b = 2%k, i = 2;
		while (!A[b]) {
			A[b] = i++;
			ll t = b; b = (a+b)%k; a = t;
		}
		printf("%lld\n", A[b]);
	}
}
