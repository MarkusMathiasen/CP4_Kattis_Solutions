#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll N = 1e6+1;

ll A[N];
ll n, mod = 1e7;

void printA(ll start, ll goal) {
	rep(i, start, goal)
		printf("%lld ", A[i]);
	printf("\n");
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll d = 1;
	rep(i, 1, N) {
		d *= i;
		while (d%10 == 0)
			d /= 10;
		d %= mod;
		A[i] = d%10;
	}
	while ((cin >> n), n) {
		printf("%lld\n", A[n]);
	}
}
