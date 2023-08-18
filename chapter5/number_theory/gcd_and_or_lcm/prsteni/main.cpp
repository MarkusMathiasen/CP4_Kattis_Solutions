#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int pr, n=1, d=1;

void reduce(int nom, int den) {
    rep(i, 2, 1000) {
        if (nom%i == 0 && den%i == 0) {
            nom /= i, den /= i;
            i--;
        }
    }
    n = nom;
    d = den;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    int N; scanf("%d", &N);
    scanf("%d", &pr);
    rep(i, 1, N) {
        int r; scanf("%d", &r);
        reduce(pr*n, r*d);
        printf("%d/%d\n", n, d);
        pr = r;
    }
}
