#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int K;

int calc(int target, int siz) {
	if (target == siz) return 0;
	else if (target*2 <= siz) return 1+calc(target, siz/2);
	else return 1+calc(target-siz/2, siz/2);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> K;
	int siz = 1;
	while (siz < K) siz <<= 1;
	int breaks = calc(K, siz);
	printf("%d %d\n", siz, breaks);
}
