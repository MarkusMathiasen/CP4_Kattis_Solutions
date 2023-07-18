#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;

vi uf;
int find(int a) {
	if (uf[a] == a) return a;
	return uf[a] = find(uf[a]);
}
void join(int a, int b) {
	int x = find(a), y = find(b);
	uf[x] = y;
}

int main() {
	scanf("%d%d", &n, &m);
	uf.assign(n, 0);
	rep(i, 1, n) uf[i] = i;
	while (m--) {
		int a, b; scanf("%d%d", &a, &b); a--, b--;
		join(a, b);
	}
	bool connected = true;
	rep(i, 0, n)
		if (find(i) != find(0))
			printf("%d\n", i+1),
			connected = false;
	if (connected)
		printf("Connected\n");
}
