#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
    ll T; cin >> T;
    while (T--) {
        ll n, m; cin >> n >> m;
        string s(n, '?');
        bool possible = true;
        while (m--) {
            ll j; cin >> j; j--;
            string suf; cin >> suf;
            for (ll i = 0; i < sz(suf) && possible; i++) {
                if (suf[i] == '*') break;
                if (s[j+i] == '?') s[j+i] = suf[i];
                possible &= s[j+i] == suf[i];
            }
            for (ll i = 1; i <= sz(suf) && possible; i++) {
                if (suf[sz(suf)-i] == '*') break;
                if (s[n-i] == '?') s[n-i] = suf[sz(suf)-i];
                possible &= s[n-i] == suf[sz(suf)-i];
            }
        }
        rep(i, 0, n) possible &= s[i] != '?';
        if (!possible) printf("IMPOSSIBLE\n");
        else printf("%s\n", s.c_str());
    }
}