#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll mod = 1e9+7;

ll n, k, choose[100001][51];
vi A;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	rep(i, 0, n+1) rep(j, 0, k+1) {
		if (j > i) continue;
		else if (i == j || j == 0) choose[i][j] = 1;
		else choose[i][j] = (choose[i-1][j-1] + choose[i-1][j])%mod;
	}
	A.assign(n, 0);
	rep(i, 0, n) cin >> A[i];
	sort(all(A));
	ll p = k-1;
	ll res = 0;
	while (p < n) {
		res = (res + choose[p][k-1]*A[p])%mod;
		p++;
	}
	printf("%lld\n", res);
}
