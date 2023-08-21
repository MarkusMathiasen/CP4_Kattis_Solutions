#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

const ll L = 1, H = 50001;

ll n;
string s1, s2;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while ((cin >> n), n) {
		ll low = L, high = H;
		vi A;
		while (n--) {
			ll i;
			cin >> s1 >> s2 >> i;
			if (s1 == "less")
				high = min(high, i-1);
			else if (s1 == "greater")
				low = max(low, i+1);
			else if (s1 == "divisible")
				A.push_back(i);
		}
		if (high == H) {
			printf("infinite\n");
			continue;
		}
		bool found = false;
		rep(i, low, high+1) {
			bool valid = true;
			for (ll x : A) valid &= i%x == 0;
			if (valid)
				found = true,
				printf("%lld ", i);
		}
		if (!found) printf("none");
		printf("\n");
	}
}
