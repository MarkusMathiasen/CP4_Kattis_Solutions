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
    string s;
    vector<int> lengths;
    int max_length = 0;
    while (getline(cin, s) && s != "") {
        lengths.push_back(sz(s));
        max_length = max(max_length, (int)s.length());
    }
    int ragged = 0;
    for (int x : lengths) {
        ragged += (max_length - x)*(max_length - x);
    }
    ragged -= (max_length - lengths.back())*(max_length - lengths.back());
    printf("%d\n", ragged);
}
