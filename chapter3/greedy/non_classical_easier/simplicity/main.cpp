#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string s;
vi a(26, 0);

int sum_of_a() {
    int res = 0;
    rep(i,0,26) {
        res += a[i];
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    string s; cin >> s;
    for (char c : s)
        a[c - 'a']++;
    sort(a.rbegin(), a.rend());
    printf("%d\n", sum_of_a() - a[0] - a[1]);
}
