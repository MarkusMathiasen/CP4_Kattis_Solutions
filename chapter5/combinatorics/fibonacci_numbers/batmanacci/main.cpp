#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

ll N, K;
vi fib;

char letter(ll n, ll k) {
	if (n == 1) return 'N';
	if (n == 2) return 'A';
	if (fib[n-2] >= k) return letter(n-2, k);
	else return letter(n-1, k-fib[n-2]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> K;
	fib.assign(N+1, 0);
	fib[1] = 1;
	rep(i, 2, N+1) fib[i] = min((ll)1e18, fib[i-1] + fib[i-2]);
	printf("%c\n", letter(N, K));
}
