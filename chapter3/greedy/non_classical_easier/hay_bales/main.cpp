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
    string s; cin >> s;
    int res = 0;
    rep(k,0,sz(s)) {
        rep(i, 0, sz(s)) {
            if (s[i] == 'C') {
                int j = i;
                while (j > 1 && s[j - 2] == 'P') {
                    swap(s[j], s[j - 2]);
                    j -= 2;
                    res++;
                }
            }
        }
        rep(i, 1, sz(s)) {
            if (s[i] == 'C' && s[i - 1] == 'P') {
                swap(s[i], s[i - 1]);
                res++;
                break;
            }
        }
    }
    printf("%d\n", res);
}
