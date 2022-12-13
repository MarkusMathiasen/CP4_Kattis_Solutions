#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef vector<ll> vi;



int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    int n, k; scanf("%d %d", &n, &k);
    int res = 1;
    while (n) {
        res++;
        n = n - (n+k-1)/k;
    }
    printf("%d\n", res);
}
