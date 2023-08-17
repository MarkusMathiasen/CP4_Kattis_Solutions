#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

const int N = 1e7+1;

bitset<N> b;
vi p;
ll T;
string s;

void sieve() {
	b.set();
	b[0] = b[1] = 0;
	rep(i, 2, N) if (b[i]) {
		for (ll j = i*i; j <= N; j += i) b[j] = 0;
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

ll to_dec(string& s, ll v) {
	ll res = 0;
	for (char c : s) {
		res *= v;
		ll val = isalpha(c) ? c-'A'+10 : c-'0';
		if (val >= v) return -1;
		res += val;
	}
	return res;
}

int main() {
	sieve();
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	vi sys = {2, 8, 10, 16};
	while (T--) {
		cin >> s;
		ll denom = 4, num = 0;
		for (ll k : sys) {
			ll x = to_dec(s, k);
			if (x == -1) denom--;
			else if (is_prime(x)) num++;
		}
		ll g = gcd(denom, num);
		printf("%lld/%lld\n", num/g, denom/g);
	}
}
