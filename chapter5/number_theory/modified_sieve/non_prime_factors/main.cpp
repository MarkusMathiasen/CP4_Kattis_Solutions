#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

const ll R = 2e6+1;

vi num_dp(R, 0), num_div(R, 1);

void fill_num_dp() {
	rep(i, 2, R) if (num_dp[i] == 0)
		for (ll j = i; j < R; j += i)
			num_dp[j]++;
}

void fill_num_div() {
	num_div[0] = 0;
	rep(i, 2, R) if (num_div[i] == 1) {
		for (ll j = i; j < R; j += i) {
			ll mul = 2, cp = j/i;
			while (cp%i == 0)
				mul++,
				cp /= i;
			num_div[j] *= mul;
		}
	}
}

ll T, n, ans[R];

int main() {
	fill_num_dp();
	fill_num_div();
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n;
		printf("%lld\n", num_div[n]-num_dp[n]);
	}
}
