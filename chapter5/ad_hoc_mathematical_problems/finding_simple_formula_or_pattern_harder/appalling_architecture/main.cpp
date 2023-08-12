#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
vector<string> A;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	A.assign(n, "");
	rep(i, 0, n) cin >> A[i];
	int x = 0, sum = 0;
	rep(i, 0, n) rep(j, 0, m) if (A[i][j] != '.')
		x += j, sum++;
	int mod = x%sum;
	x /= sum;
	if (mod > sum/2) x++;
	int left = 0;
	while (A[n-1][left] == '.') left++;
	int right = m-1;
	while (A[n-1][right] == '.') right--;
	if (x < left) printf("left\n");
	else if (x > right) printf("right\n");
	else printf("balanced\n");
}
