#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll h(ll n) {
	if (n == 1) return 1;
	else if (n%2) return n+h(n*3+1);
	else return n+h(n/2);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n; cin >> n;
	printf("%lld\n", h(n));
}
