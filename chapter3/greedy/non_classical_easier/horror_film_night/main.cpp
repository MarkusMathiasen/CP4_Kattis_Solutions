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
    int n1; scanf("%d", &n1);
    vi a1(n1);
    rep(i,0,n1) scanf("%d", &a1[i]);
    int n2; scanf("%d", &n2);
    vi a2(n2);
    rep(i,0,n2) scanf("%d", &a2[i]);
    sort(all(a1));
    sort(all(a2));
    int p1 = 0, p2 = 0;
    int res = 0;
    while (p1 < n1 || p2 < n2) {
        res++;
        if (p1 == n1 || p2 == n2) {
            break;
        }
        if (a1[p1] < a2[p2]) {
            while (p1 < n1 && a1[p1] < a2[p2]) {
                p1++;
            }
        }
        else if (a1[p1] > a2[p2]) {
            while (p2 < n2 && a1[p1] > a2[p2]) {
                p2++;
            }
        } else if (a1[p1] == a2[p2]) {
            p1++;
            p2++;
        } else assert(false);
    }
    printf("%d\n", res);
}
