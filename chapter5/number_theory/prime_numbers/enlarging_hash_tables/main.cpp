#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

const ll N = 80001;

bitset<N> b;
vi p;
ll n;

void sieve() {
	b.set();
	b[0] = b[1] = 0;
	rep(i, 2, N) if (b[i]) {
		for (ll j = i*i; j < N; j += i) b[j] = 0;
		p.push_back(i);
	}
}

bool is_prime(ll x) {
	if (x < N) return b[x];
	for (ll i = 0; p[i]*p[i] <= x; i++)
		if (x%p[i] == 0)
			return false;
	return true;
}

int main() {
	sieve();
	cin.tie(0)->sync_with_stdio(0);
	while ((cin >> n), n) {
		ll nn = 2*n;
		while (!is_prime(nn)) nn++;
		printf("%lld", nn);
		if (!is_prime(n)) printf(" (%lld is not prime)", n);
		printf("\n");
	}
}
