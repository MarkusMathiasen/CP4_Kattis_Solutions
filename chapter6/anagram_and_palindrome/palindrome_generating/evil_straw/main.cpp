#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n;
string s;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	while (n--) {
		cin >> s;
		// Check if impossible
		vi freq(26, 0);
		for (char c : s) freq[c-'a']++;
		ll odds = 0;
		for (ll f : freq) odds += f%2;
		if (odds != sz(s)%2) {
			printf("Impossible\n");
			continue;
		}
		// Now I know it is possible
		ll l = 0, r = sz(s)-1;
		ll res = 0;
		while (l < r) {
			ll r2 = r;
			while (s[r2] != s[l]) r2--;
			if (r2 == l) {
				swap(s[r2], s[r2+1]);
				res++;
				continue;
			}
			while (r2 < r) {
				swap(s[r2], s[r2+1]);
				r2++; res++;
			}
			r--;
			l++;
		}
		printf("%lld\n", res);
	}
}
