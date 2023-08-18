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

ll sum_div(ll n) {
	ll res = 1;
	for (ll i = 0; p[i]*p[i] <= N; i++) {
		ll mul = 1, sum = 1;
		while (n%p[i] == 0) {
			mul *= p[i];
			sum += mul;
			n /= p[i];
		}
		res *= sum;
	}
	if (n > 1) res *= n+1;
	return res;
}

int main() {
	sieve();
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> n) {
		ll d = sum_div(n) - n;
		printf("%lld ", n);
		if (d == n) printf("perfect\n");
		else if (d-2 <= n && d+2 >= n) printf("almost perfect\n");
		else printf("not perfect\n");
	}
}
