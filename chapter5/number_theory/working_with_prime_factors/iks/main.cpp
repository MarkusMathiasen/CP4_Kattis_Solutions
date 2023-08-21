#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

const ll N = 1e6+1;

bitset<N> b;
unordered_map<ll, ll> toi;
vi p, cnt, A;
ll n;

void sieve() {
	b.set();
	b[0] = b[1] = 0;
	rep(i, 2, N) if (b[i]) {
		for (ll j = i*i; j < N; j += i) b[j] = 0;
		toi[i] = sz(p);
		p.push_back(i);
		cnt.push_back(0);
	}
}

void count(ll n) {
	for (ll i = 0; p[i]*p[i] <= n; i++)
		while (n%p[i] == 0)
			n /= p[i],
			cnt[i]++;
	if (n > 1)
		cnt[toi[n]]++;
}

int main() {
	sieve();
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	A.assign(n, 0);
	rep(i, 0, n) cin >> A[i];
	rep(i, 0, n) count(A[i]);
	ll a = 1, b = 0;
	rep(i, 0, sz(cnt)) {
		if (cnt[i]/n) {
			// change a
			ll val = 1;
			rep(j, 0, cnt[i]/n) val *= p[i];
			a *= val;
			// change b
			rep(j, 0, n) {
				ll num = A[j], am = 0;
				while (num%p[i] == 0)
					num /= p[i],
					am++;
				if (am < cnt[i]/n)
					b += cnt[i]/n - am;
			}
		}
	}
	printf("%lld %lld\n", a, b);
}
