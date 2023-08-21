#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll pt, p1, p2;

void read_num(ll& x) {
	ll a, b; scanf("%lld.%lld", &a, &b);
	x = a*100+b;
}

int main() {
	read_num(pt);
	read_num(p1);
	read_num(p2);
	bool found = false;
	for (ll i = 0; i*p1 <= pt; i++) {
		ll rem = pt - i*p1;
		if (rem%p2 == 0)
			found = true,
			printf("%lld %lld\n", i, rem/p2);
	}
	if (!found) printf("none\n");
}
