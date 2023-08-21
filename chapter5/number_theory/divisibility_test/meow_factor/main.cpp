#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	ll res = 1;
	for (ll i = 2; i <= 200; i++) {
		ll cp = n;
		bool possible = true;
		rep(j, 0, 9) {
			possible &= cp%i == 0;
			cp /= i;
		}
		if (possible) res = i;
	}
	printf("%lld\n", res);
}
