#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll N = 1e6+1;

ll n;
long double dp[N];

int main() {
	dp[0] = 1;
	dp[1] = 0;
	rep(i, 2, N) 
		dp[i] = (i-1)/(long double)i*(1.0L/(i-1)*dp[i-2] + dp[i-1]);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	printf("%Lf\n", 1 - dp[min(N-1, n)]);
}
