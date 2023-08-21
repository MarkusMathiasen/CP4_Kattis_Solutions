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

ll n, m;

int main() {
	sieve();
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> n >> m) {
		bool res = true;
		printf("%lld ", m);
		if (m == 1 && n == 0) goto end;
		for (ll i = 0; p[i]*p[i] <= m; i++) {
			if (m%p[i] == 0) {
				ll e1 = 0;
				while (m%p[i] == 0) {
					e1++;
					m /= p[i];
				}
				ll e2 = 0, mul = p[i];
				while (mul <= n) {
					e2 += n/mul;
					mul *= p[i];
				}
				res &= e1 <= e2;
			}
		}
		res &= m <= n;
		res &= m != 0;
end:
		if (res) printf("divides %lld!\n", n);
		else printf("does not divide %lld!\n", n);
	}
}
