#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

bool winning(ll a, ll b) {
	if (a == 0) return false;
	return !winning(b%a, a) || a*2 <= b;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll a, b;
	while ((cin >> a >> b), a || b) {
		if (winning(min(a, b), max(a, b)))
			printf("Stan wins\n");
		else
			printf("Ollie wins\n");
	}
}
