#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int to_dec(string num, string sys) {
    int dec = 0;
    int base = 1;
    for (int i = sz(num)-1; i >= 0; i--) {
        int digit = (int)sys.find(num[i]);
        dec += digit * base;
        base *= sz(sys);
    }
    return dec;
}

string to_sys(int num, string sys) {
    string ans = "";
    while (num > 0) {
        int digit = num % sz(sys);
        ans += sys[digit];
        num /= sz(sys);
    }
    reverse(all(ans));
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    int T; cin >> T;
    rep(t, 1, T+1) {
        string num, sys1, sys2; cin >> num >> sys1 >> sys2;
        int dec = to_dec(num, sys1);
        string ans = to_sys(dec, sys2);
        cout << "Case #" << t << ": " << ans << endl;
    }
}
