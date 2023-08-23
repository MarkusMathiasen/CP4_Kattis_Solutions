#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
vector<long double> ans = {
	0.993426,
	0.993426,
	0.993426,
	0.993426,
	0.993426,
	0.993426,
	0.993425,
	0.993417,
	0.993400,
	0.993362,
	0.993267,
	0.993023,
	0.992576,
	0.991724,
	0.989861,
	0.986008,
	0.981013,
	0.972551,
	0.959826,
	0.942153,
	0.918872,
	0.893027,
	0.855602,
	0.807739,
	0.748373,
	0.680331,
	0.606990,
	0.524759,
	0.435420,
	0.346293,
	0.263790,
	0.194015,
	0.135813,
	0.086775,
	0.052618,
	0.028908,
	0.015678,
	0.007502,
	0.002686,
	0.000956,
	0.000146
};

ll T, n;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n;
		printf("%Lf\n", ans[n]);
	}
}
