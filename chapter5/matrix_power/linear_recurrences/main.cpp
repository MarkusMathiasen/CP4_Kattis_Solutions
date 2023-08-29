#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll N, Q, MOD, T;
vi A;
vector<vi> mat, X;

ll mod(ll x) {
	return ((x%MOD)+MOD)%MOD;
}

vector<vi> mat_mul(vector<vi>& A, vector<vi>& B) {
	ll n = sz(A), m = sz(A[0]), l = sz(B[0]);
	vector<vi> res(n, vi(l, 0));
	rep(i, 0, n) rep(j, 0, l) rep(k, 0, m)
		res[i][j] = mod(res[i][j] + mod(A[i][k] * B[k][j]));
	return res;
}

vector<vi> mat_pow(vector<vi>& A, ll p) {
	if (p == 0) {
		vector<vi> res(sz(A), vi(sz(A), 0));
		rep(i, 0, sz(A)) res[i][i] = mod(1);
		return res;
	}
	if (p == 1) return A;
	vector<vi> res = mat_pow(A, p/2);
	res = mat_mul(res, res);
	if (p%2) res = mat_mul(res, A);
	return res;
}

void print_mat() {
	rep(i, 0, sz(mat)) {
		rep(j, 0, sz(mat)) printf("%3lld ", mat[i][j]);
		printf("\n");
	}
	printf("\n");
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	A.assign(N+1, 0);
	rep(i, 0, N+1) cin >> A[i];
	X.assign(N+1, vi(1, 1));
	rep(i, 0, N) cin >> X[N-i-1][0];
	mat.assign(N+1, vi(N+1, 0));
	rep(i, 0, N) mat[0][i] = A[i+1];
	mat[0][N] = A[0];
	rep(i, 0, N-1) mat[i+1][i] = 1;
	mat[N][N] = 1;
	cin >> Q;
	while (Q--) {
		cin >> T >> MOD;
		vector<vi> mp = mat_pow(mat, T);
		vector<vi> mm = mat_mul(mp, X);
		printf("%lld\n", mm[N-1][0]);
	}
}
