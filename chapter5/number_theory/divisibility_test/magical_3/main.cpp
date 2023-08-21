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

void sieve() {
	b.set();
	b[0] = b[1] = 0;
	rep(i, 2, N) if (b[i]) {
		for (ll j = i*i; j < N; j += i) b[j] = 0;
		p.push_back(i);
	}
}

ll calc(ll n) {
	if (n%4 == 0) return 4;
	if (n%5 == 0) return 5;
	if (n%2 == 0 && n%3 == 0) return 6;
	if (n%7 == 0) return 7;
	if (n%9 == 0) return 9;
	for (ll i = 4; p[i]*p[i] <= n; i++)
		if (n%p[i] == 0) return p[i];
	if (n%3 == 0) return n/3;
	if (n%2 == 0) return n/2;
	return n;
}

ll n;

int main() {
	sieve();
	cin.tie(0)->sync_with_stdio(0);
	while ((cin >> n), n) {
		if (n == 1 || n == 2 || n == 4 || n == 5 || n == 6) {
			printf("No such base\n");
			continue;
		}
		if (n == 3) printf("4\n");
		else printf("%lld\n", calc(n-3));
	}
}
