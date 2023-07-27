#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	int f, s, g, u, d; scanf("%d%d%d%d%d", &f, &s, &g, &u, &d); s--, g--;
	vi dist(f, -1);
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		if (v+u < f && dist[v+u] == -1)
			dist[v+u] = dist[v]+1,
			q.push(v+u);
		if (v-d >= 0 && dist[v-d] == -1)
			dist[v-d] = dist[v]+1,
			q.push(v-d);
	}
	if (dist[g] == -1) printf("use the stairs\n");
	else printf("%d\n", dist[g]);
}
