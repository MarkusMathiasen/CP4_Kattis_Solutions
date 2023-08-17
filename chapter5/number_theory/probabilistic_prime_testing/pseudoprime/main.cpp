#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

const ll N = 1e6+1;

ll p, a;
bitset<N> b;
vi pr;

void sieve() {
	b.set();
	b[0] = b[1] = 0;
	rep(i, 2, N) if (b[i]) {
		for (ll j = i*i; j <= N; j += i) b[j] = 0;
		pr.push_back(i);
	}
}

bool is_prime(ll x) {
	if (x < N) return b[x];
	for (ll i = 0; pr[i]*pr[i] <= x; i++)
		if (x%pr[i] == 0)
			return false;
	return true;
}

ll pow(ll a, ll b, ll m) {
	if (b == 0) return 1;
	if (b == 1) return a % m;
	ll p = pow(a, b/2, m);
	p = (p*p)%m;
	return (p*(b%2?a:1))%m;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	sieve();
	while ((cin >> p >> a), p || a) {
		if (is_prime(p) || pow(a%p, p, p) != a%p)
			printf("no\n");
		else
			printf("yes\n");
	}
}
