#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n;
	while (cin >> n) {
		ll p = 1;
		while (true) {
			p *= 9;
			if (p >= n) {
				printf("Stan wins.\n");
				break;
			}
			p *= 2;
			if (p >= n) {
				printf("Ollie wins.\n");
				break;
			}
		}
	}
}
