#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll K, T, P, Q, X1;
vi X;
vector<long double> pr;
vector<vector<long double>> dp;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> K >> T >> P >> Q >> X1;
	X.push_back(X1);
	rep(i, 1, T) {
		X1 = (X1*P)%Q;
		X.push_back(X1);
	}
	for (ll& x : X) x %= 4;
	rep(i, 0, T) {
		vi W(4, 0);
		rep(i, 0, 4) cin >> W[i];
		long double prob01 = (long double)W[X[i]]/(W[X[i]]+W[X[i]^1]);
		long double prob23 = (long double)W[X[i]^2]/(W[X[i]^2]+W[X[i]^3]);
		long double prob32 = (long double)W[X[i]^3]/(W[X[i]^2]+W[X[i]^3]);
		long double prob02 = (long double)W[X[i]]/(W[X[i]]+W[X[i]^2]);
		long double prob03 = (long double)W[X[i]]/(W[X[i]]+W[X[i]^3]);
		pr.push_back(prob01*(prob23*prob02 + prob32*prob03));
	}
	dp.assign(T+1, vector<long double>(T+1, 0));
	dp[0][0] = 1;
	rep(t, 0, T) rep(k, 0, T) {
		dp[t+1][k+1] += dp[t][k]*pr[t];
		dp[t+1][k] += dp[t][k]*(1-pr[t]);
	}
	long double res = 0;
	rep(k, K, T+1) res += dp[T][k];
	printf("%Lf\n", res);
}
