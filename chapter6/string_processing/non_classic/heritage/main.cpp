#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll mod = 1e9+7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n; string name; cin >> n >> name;
	vi dp(sz(name)+1, 0);
	dp[0] = 1;
	vector<string> A(n);
	vi B(n);
	rep(i, 0, n) cin >> A[i] >> B[i];
	rep(i, 1, sz(name)+1) {
		rep(j, 0, n)
			if (sz(A[j]) <= i && name.substr(i-sz(A[j]), sz(A[j])) == A[j])
				dp[i] = (dp[i]+dp[i-sz(A[j])]*B[j])%mod;
	}
	printf("%lld\n", dp[sz(name)]);
}
