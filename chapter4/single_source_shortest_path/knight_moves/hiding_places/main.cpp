#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    int T; scanf("%d", &T);
    while (T--) {
        char a, b; scanf(" %c%c", &a, &b);
        a -= 'a', b -= '1';
        vector<vi> dist(8, vi(8, -1));
        queue<vi> q; q.push({0, a, b});
        while (!q.empty()) {
            int d = q.front()[0];
            int a = q.front()[1];
            int b = q.front()[2];
            q.pop();
            if (a < 0 || b < 0 || a > 7 || b > 7 || dist[a][b] != -1)
                continue;
            dist[a][b]=d;
            vi x = {-2, -2, -1, -1, 1, 1, 2, 2};
            vi y = {-1, 1, -2, 2, -2, 2, -1, 1};
            rep(i, 0, 8) q.push({d+1, a+x[i], b+y[i]});
        }
        int d = 0;
        vector<pii> res;
        for (int j = 7; j >= 0; j--) rep(i, 0, 8)
            if (dist[i][j] > d)
                res = {pii('a'+i, '1'+j)},
                d = dist[i][j];
            else if (dist[i][j] == d)
                res.emplace_back('a'+i, '1'+j);
        printf("%d", d);
        for (pii p : res) printf(" %c%c", p.first, p.second);
        printf("\n");
    }
}
