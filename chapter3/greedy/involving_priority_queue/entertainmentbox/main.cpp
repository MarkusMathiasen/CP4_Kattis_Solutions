#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, k, res = 0;
vector<pii> shows;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    scanf("%d%d", &n, &k);
    shows.assign(n, {0, 0});
    rep(i, 0, n)
        scanf("%d%d", &shows[i].first, &shows[i].second);
    sort(all(shows));
    multiset<int> s;
    rep(i, 0, k) s.insert(0);
    for (auto show : shows) {
        int start = show.first, end = show.second;
        int earliest = *s.begin();
        int latest = *s.rbegin();
        if (start >= earliest) {
            s.erase(s.begin());
            s.insert(end);
            res++;
        } else if (end <= latest) {
            s.erase(s.find(latest));
            s.insert(end);
        }
    }
    printf("%d\n", res);
}
