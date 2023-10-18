#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll inf = 1e9;

template<class T>
ll string_align(const vector<T>& A, const vector<T>& B, vector<vi>& dp) {
    dp.assign(sz(A)+1, vi(sz(B)+1, 0));
    rep(i, 0, sz(A)+1) dp[i][0] = i*(0); // delete score 0
    rep(j, 1, sz(B)+1) dp[0][j] = j*(0); // insert score 0
    rep(i, 1, sz(A)+1) rep(j, 1, sz(B)+1) {
        // match and mismatch score (1 and -inf)
        dp[i][j] = dp[i - 1][j - 1] + (A[i - 1] == B[j - 1] ? 1 : -inf);
        dp[i][j] = max(dp[i][j], dp[i - 1][j]); // delete 0
        dp[i][j] = max(dp[i][j], dp[i][j - 1]); // insert 0
    }
    return dp[sz(A)][sz(B)];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	while ((cin >> s), s != ".") {
		// Read input
		vector<string> A, B;
		A.push_back(s);
		while ((cin >> s), s != ".")
			A.push_back(s);
		while ((cin >> s), s != ".")
			B.push_back(s);
		A.push_back(".");
		B.push_back(".");

		// Find res
		reverse(all(A)); reverse(all(B));
		vector<vi> dp;
		string_align(A, B, dp);
		ll a = sz(A), b = sz(B);
		vector<string> res;
		while (a > 0 && b > 0) {
			if (A[a-1] == B[b-1])
				res.push_back(A[a-1]), a--, b--;
			else if (dp[a-1][b] > dp[a][b-1]
				|| (dp[a-1][b] == dp[a][b-1]
				&& A[a-1] < B[b-1]))
				res.push_back(A[--a]);
			else res.push_back(B[--b]);
		}

		// Print res
		for (string& s : res) printf("%s ", s.c_str());
		printf("\n");
	}
}
