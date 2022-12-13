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
    //cin.exceptions(cin.failbit);1]);
    ll d; scanf("%lld", &d);
    ll money = 100;
    ll stocks = 0;
    ll price; scanf("%lld", &price);
    rep(i, 0, d-1) {
        ll x; scanf("%lld", &x);
        if (x > price) {
            ll buy = min((ll)100000-stocks, money/price);
            stocks += buy;
            money -= buy*price;
        } else if (x < price) {
            money += stocks*price;
            stocks = 0;
        }
        price = x;
    }
    money += stocks*price;
    printf("%lld\n", money);
}
