#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll N, b;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> b;
	printf(N < 1ll<<(b+1) ? "yes\n" : "no\n");
}
