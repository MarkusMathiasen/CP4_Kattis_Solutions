#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int m, a, b, c;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> m >> a >> b >> c;
	if (a+b-m+c <= m) printf("possible\n");
	else printf("impossible\n");
}
