#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    int T; cin >> T;
    rep(t, 1, T+1) {
        int S; cin >> S;
        string line; getline(cin, line);
        vector<string> engines;
        while (S--) {
            getline(cin, line);
            engines.push_back(line);
        }
        int Q; cin >> Q; getline(cin, line);
        int res = 0;
        set<string> cands(all(engines));
        while (Q--) {
            getline(cin, line);
            cands.erase(line);
            if (cands.empty()) {
                cands.insert(all(engines));
                cands.erase(line);
                res++;
            }
        }
        printf("Case #%d: %d\n", t, res);
    }
}
