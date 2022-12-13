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
    //cin.exceptions(cin.failbit);1]);
    int n, p; scanf("%d %d", &n, &p);
    vi scores(n);
    int sum = 0;
    rep(i,0,n) {
        int x; scanf("%d", &x);
        sum += x;
    }
    int res = 0;
    while (p*n > sum) {
        if (p == 100) {
            printf("impossible\n");
            return 0;
        }
        sum += 100;
        n++, res++;
    }
    printf("%d\n", res);
}
