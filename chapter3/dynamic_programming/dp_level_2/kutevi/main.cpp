#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N, K, dp[360];
vi A;

void fill(int a) {
	if (dp[a]) return;
	dp[a] = 1;
	for (int x : A) {
		fill((a-x+360)%360);
		fill((a+x)%360);
	}
}

int main() {
	scanf("%d%d", &N, &K);
	A.assign(N, 0);
	rep(i, 0, N)
		scanf("%d", &A[i]);
	rep(i, 0, N)
		fill(A[i]);
	rep(i, 0, K) {
		int x; scanf("%d", &x);
		printf(dp[x] ? "YES\n" : "NO\n");
	}
}
