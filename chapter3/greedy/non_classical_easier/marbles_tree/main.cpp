#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef vector<ll> vi;

ll n;
vector<vi> tree;
vi marble_sum, node_sum, p;

void dfs(ll v) {
    for (ll u : tree[v]) {
        dfs(u);
        marble_sum[v] += marble_sum[u];
        node_sum[v] += node_sum[u];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    while (scanf("%lld", &n), n) {
        tree.assign(n, vi());
        marble_sum.assign(n, 0);
        node_sum.assign(n, 1);
        p.assign(n, -1);
        rep(i, 0, n) {
            ll m, d;
            scanf("%lld%lld%lld", &m, &m, &d);
            rep(j, 0, d) {
                ll c;
                scanf("%lld", &c); c--;
                tree[i].push_back(c);
                p[c] = i;
            }
            marble_sum[i] = m;
        }
        int root = -1;
        rep(i, 0, n) if (p[i] == -1) root = i;
        dfs(root);
        ll res = 0;
        rep(i, 0, n) {
            res += abs(marble_sum[i] - node_sum[i]);
        }
        printf("%lld\n", res);
    }
}
