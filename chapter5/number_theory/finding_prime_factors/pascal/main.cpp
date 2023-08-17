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

int main() {
	sieve();
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (ll i = 0; p[i]*p[i] <= n; i++) {
		if (n%p[i] == 0) {
			printf("%lld\n", n-n/p[i]);
			return 0;
		}
	}
	if (n == 1) printf("0\n");
	else printf("%lld\n", n-1);
}
