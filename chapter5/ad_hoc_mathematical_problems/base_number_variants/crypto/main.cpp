#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll N; cin >> N;
	ll res = 1;
	ll val = 0;
	for (ll i = 2; i*i <= N; i++) {
		ll cpy = N;
		ll nval = 0;
		while (cpy % i == 0)
			nval++, cpy /= i;
		if (nval > val)
			val = nval, res = i;
	}
	if (val == 0)
		res = N;
	printf("%lld\n", res);
}
