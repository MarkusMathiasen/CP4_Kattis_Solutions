#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void print(int l, int w) {
	if (l == 0) return;
	if (w-26 >= l-1) {
		printf("z");
		print(l-1, w-26);
	} else {
		printf("%c", 'a' + (w-l));
		print(l-1, l-1);
	}
}

int main() {
	int l, w; scanf("%d%d", &l, &w);
	if (l > w || l*26 < w) {
		printf("impossible\n");
		return 0;
	}
	print(l, w);
	printf("\n");
}
