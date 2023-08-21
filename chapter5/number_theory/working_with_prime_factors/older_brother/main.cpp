#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

const ll N = 1e5+1;

bitset<N> b;

bool sieve(ll n) {
	b.set();
	rep(i, 2, N) if (b[i]) {
		for (ll j = i*i; j < N; j += i) b[j] = 0;
		if (n%i == 0) {
			while (n%i == 0) n/= i;
			return n == 1;
		}
	}
	return n > 1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n; cin >> n;
	printf(sieve(n) ? "yes\n" : "no\n");
}
