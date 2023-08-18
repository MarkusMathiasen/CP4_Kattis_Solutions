#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const int N = 1e5+1;

bitset<N> b;
vi p;
ll n;


void sieve() {
	b.set();
	b[0] = b[1] = 0;
	rep(i, 2, N) if (b[i]) {
		for (ll j = i*i; j <= N; j += i) b[j] = 0;
		p.push_back(i);
	}
}

void factor(ll n) {
	for (ll i = 0; p[i]*p[i] <= n; i++) {
		ll cnt = 0;
		while (n%p[i] == 0)
			n /= p[i],
			cnt++;
		if (cnt == 1) printf("%lld ", p[i]);
		else if (cnt > 1) printf("%lld^%lld ", p[i], cnt);
	}
	if (n > 1) printf("%lld ", n);
	printf("\n");
}

int main() {
	sieve();
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> n) {
		if (n < 0) {
			printf("-1 ");
			n = -n;
		}
		factor(n);
	}
}
