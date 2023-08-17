#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll N = 32001;

bitset<N> b;
vi p;
ll T, n;

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
	cin >> T;
	while (T--) {
		cin >> n;
		vector<pii> res;
		for (ll i = 0; p[i] < n; i++) {
			ll j = i;
			while (p[i]+p[j] < n) j++;
			if (p[i]+p[j] == n)
				res.push_back({p[i],p[j]});
		}
		printf("%lld has %d representation(s)\n", n, sz(res));
		for (auto& [a,b] : res) printf("%lld+%lld\n", a, b);
		printf("\n");
	}
}
