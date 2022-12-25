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
    string s; cin >> s;
    vector<char> L(sz(s));
    int k = 0;
    rep(i, 0, sz(s)) {
        ll pos = lower_bound(L.begin(), L.begin()+k, s[i]) - L.begin();
        L[pos] = s[i];
        k += pos == k;
    }
    printf("%d\n", 26-k);
}
