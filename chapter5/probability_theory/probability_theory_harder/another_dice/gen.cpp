#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll S = 1<<6, P = 41, D = 9;

long double dp[S][P][D];
vi dice;

bool inc() {
	ll pos = 0;
	while (pos < sz(dice)) {
		dice[pos] = (dice[pos]+1)%6;
		if (dice[pos] == 0) {
			pos++;
			continue;
		}
		break;
	}
	return pos < sz(dice);
}

void print_dice() {
	for (ll x : dice) printf("%lld ", x);
	printf("\n");
}

int main() {
	// We have already won
	ll printed = 0;
	for (ll s = S-1; s >= 0; s--) rep(p, 0, P) rep(d, 0, D) {
		if (s != printed) {
			printf("%lld\n", s);
			printed = s;
		}
		if (s&1 && p == 0) {
			dp[s][p][d] = 1;
			continue;
		}
		if (d == 0) {
			dp[s][p][d] = 0;
			continue;
		}
		dice.clear();
		rep(i, 0, d) dice.push_back(0);
		long double& res = dp[s][p][d];
		ll total = 1;
		rep(i, 0, d) total *= 6;
		do {
			long double round = 0;
			vi count(6, 0);
			for (ll x : dice) count[x]++;
			rep(v, 0, 6) {
				ll np = max(0ll, p-count[v]*(v==0?5:v));
				if (count[v] > 0 && !(s&(1<<v))) {
					ll ns = s | (1<<v);
					round = max(round, dp[ns][np][d-count[v]]);
				}
			}
			res += round/total;
		} while (inc());
	}
	printf("test\n");
	rep(i, 0, P) {
		printf("%Lf\n", dp[0][i][D-1]);
	}
}
