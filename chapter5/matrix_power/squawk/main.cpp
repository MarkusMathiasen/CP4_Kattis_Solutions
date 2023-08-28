#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n, m, s, t;
vector<vi> mat;

vector<vi> mat_mul(vector<vi>& A, vector<vi>& B) {
	ll n = sz(A), m = sz(A[0]), t = sz(B[0]);
	vector<vi> res(n, vi(t, 0));
	rep(i, 0, n) rep(j, 0, t) rep(k, 0, m)
		res[i][j] += A[i][k]*B[k][j];
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> s >> t;
	mat.assign(n, vi(n, 0));
	rep(i, 0, m) {
		ll a, b; cin >> a >> b;
		mat[a][b] = mat[b][a] = 1;
	}
	if (t == 0) {
		printf("1\n");
		return 0;
	}
	vector<vi> cp(all(mat));
	rep(i, 1, t) mat = mat_mul(mat, cp);
	ll res = 0;
	rep(i, 0, n) res += mat[s][i];
	printf("%lld\n", res);
}
