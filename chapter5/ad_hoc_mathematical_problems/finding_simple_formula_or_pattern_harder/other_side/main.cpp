#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int W, S, C, K;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> W >> S >> C >> K;
	bool res;
	if (C == 0) {
		res = K > S || K > W;
		res |= K == S && K*2 >= W;
		res |= K == W && K*2 >= S;
	}
	else if (S == 0) {
		res = K || (!W && !C);
	}
	else if (W == 0) {
		res = K > S || K > C;
		res |= K == S && K*2 >= C;
		res |= K == C && K*2 >= S;
	}
	else {
		res = K > S || K > W+C;
		res |= K == S && K*2 >= (W+C);
		res |= K == W+C && K*2 >= S;
	}
	printf(res ? "YES\n" : "NO\n");
}
