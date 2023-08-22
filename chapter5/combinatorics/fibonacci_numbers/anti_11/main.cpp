#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

const ll N = 10001, mod = 1e9+7;
ll T, n, zero[N], one[N];

int main() {
	zero[0] = 1;
	one[0] = 0;
	rep(i, 1, N)
		zero[i] = zero[i-1] + one[i-1] % mod,
		one[i] = zero[i-1];
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n;
		printf("%lld\n", (zero[n]+one[n])%mod);
	}
}
