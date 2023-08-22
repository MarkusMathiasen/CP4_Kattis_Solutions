#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll R, G, B, Y, S;
long double dp[5][5][5][5][9];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> R >> G >> B >> Y >> S;
	dp[0][0][0][0][0] = 1;
	rep(r, 0, R+1) rep(g, 0, G+1) rep(b, 0, B+1) rep(y, 0, Y+1) rep(s, 0, S) {
		long long div = 2 + (r<R)+(g<G)+(b<B)+(y<Y);
		if (div == 2) break;
		long double cur = dp[r][g][b][y][s];
		if (r < R)
			dp[r+1][g][b][y][s] += cur/div;
		if (g < G)
			dp[r][g+1][b][y][s] += cur/div;
		if (b < B)
			dp[r][g][b+1][y][s] += cur/div;
		if (y < Y)
			dp[r][g][b][y+1][s] += cur/div;
		if (R-r >= G-g && R-r >= B-b && R-r >= Y-y)
			dp[r+1][g][b][y][s] += cur/div;
		else if (G-g >= R-r && G-g >= B-b && G-g >= Y-y)
			dp[r][g+1][b][y][s] += cur/div;
		else if (B-b >= R-r && B-b >= G-g && B-b >= Y-y)
			dp[r][g][b+1][y][s] += cur/div;
		else if (Y-y >= R-r && Y-y >= G-g && Y-y >= B-b)
			dp[r][g][b][y+1][s] += cur/div;
		dp[r][g][b][y][s+1] += cur/div;
	}
	long double res = 0;
	rep(i, 0, S) res += dp[R][G][B][Y][i];
	printf("%Lf\n", res);
}
