#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

bool win(ll a1, ll a2, ll b1, ll b2) {
	if (a2 > a1) swap(a1, a2);
	if (b2 > b1) swap(b2, b1);
	ll a = a1*10 + a2;
	ll b = b1*10 + b2;
	if (a == b) return false;
	if (a == 21) return true;
	if (b == 21) return false;
	for (ll i = 66; i >= 11; i -= 11) {
		if (a == i) return true;
		if (b == i) return false;
	}
	return a > b;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	char a1, a2, b1, b2;
	while ((cin >> a1 >> a2 >> b1 >> b2), a1 != '0') {
		ll wins = 0, total = 6*6*6*6;
		rep(x1, 1, 7) rep(x2, 1, 7) rep(y1, 1, 7) rep(y2, 1, 7)
			wins += win(a1=='*'?x1:a1-'0', a2=='*'?x2:a2-'0', b1=='*'?y1:b1-'0', b2=='*'?y2:b2-'0');
		if (wins == total) printf("1\n");
		else if (wins == 0) printf("0\n");
		else {
			ll d = gcd(wins, total);
			wins /= d;
			total /= d;
			printf("%lld/%lld\n", wins, total);
		}
	}
}
