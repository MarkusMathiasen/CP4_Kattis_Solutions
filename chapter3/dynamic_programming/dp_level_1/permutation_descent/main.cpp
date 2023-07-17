#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 1001113;

vector<vi> dp(101, vi(100, -1));

int calc(int N, int v) {
	if (dp[N][v] != -1) return dp[N][v];
	if (v == N-1 || v == 0) return dp[N][v] = 1;
	int rec1 = (calc(N-1, v)*(v+1)) % MOD;;
	int rec2 = (calc(N-1, v-1)*(N-v)) % MOD;
	return dp[N][v] = (rec1 + rec2) % MOD;
}

int main() {
	int P;
	scanf("%d", &P);
	while (P--) {
		int t, N, v;
		scanf("%d%d%d", &t, &N, &v);
		printf("%d %d\n", t, calc(N, v));
	}
}
