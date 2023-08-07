#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, q;
ll inf = 1L << 62, A[150][150];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    while (scanf("%d%d%d", &n, &m, &q), m | n | q) {
        rep(i, 0, n) rep(j, 0, n) A[i][j] = i == j ? 0 : inf;
        while (m--) {
            ll u, v, w;
            scanf("%lld%lld%lld", &u, &v, &w);
            A[u][v] = min(A[u][v], w);
        }
        rep(k, 0, n) rep(i, 0, n) rep(j, 0, n)if (A[i][k] != inf && A[k][j] != inf)
                        A[i][j] = max(-inf, min(A[i][j], A[i][k] + A[k][j]));
        rep(k, 0, n) if (A[k][k] < 0)
                rep(i, 0, n) rep(j, 0, n)if (A[i][k] != inf && A[k][j] != inf) A[i][j] = -inf;
        while (q--) {
            int a, b; scanf("%d%d", &a, &b);
            if (A[a][b] == inf) printf("Impossible\n");
            else if (A[a][b] == -inf) printf("-Infinity\n");
            else printf("%lld\n", A[a][b]);
        }
        printf("\n");
    }
}
