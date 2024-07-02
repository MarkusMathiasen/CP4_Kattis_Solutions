#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll w, h, n;
vector<vi> A;
vector<string> names;
vi allocated;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> w >> h >> n) {
		A.assign(w, vi(h, n));
		names.assign(n, "");
		allocated.assign(n+2, 0);
		rep(i, 0, n) {
			ll x1, y1, x2, y2; cin >> names[i] >> x1 >> y1 >> x2 >> y2;
			rep(x, x1, x2) rep(y, y1, y2) A[x][y] = A[x][y] == n ? i : n+1;
		}
		rep(i, 0, w) rep(j, 0, h) allocated[A[i][j]]++;
		printf("Total %lld\n", w*h);
		printf("Unallocated %lld\n", allocated[n]);
		printf("Contested %lld\n", allocated[n+1]);
		rep(i, 0, n) printf("%s %lld\n", names[i].c_str(), allocated[i]);
		printf("\n");
	}
}
