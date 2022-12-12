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
    int T;
    scanf("%d", &T);
    while (T--) {
        int l, n;
        scanf("%d%d", &l, &n);
        vi ants(n);
        rep(i,0,n) scanf("%d", &ants[i]);
        sort(all(ants));
        int min_time = 0, max_time = 0;
        rep(i,0,n) {
            min_time = max(min_time, min(ants[i], l-ants[i]));
            max_time = max(max_time, max(ants[i], l-ants[i]));
        }
        printf("%d %d\n", min_time, max_time);
    }
}
