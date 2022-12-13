#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct card {
    int buy, sell;
    ll tbuy, tsell;
};

int N, T, K;
vi deck;
vector<card> cards;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);1]);
    scanf("%d %d %d", &N, &T, &K);
    deck.assign(T, 0);
    rep(i,0,N) {
        int x; scanf("%d", &x);
        deck[x-1]++;
    }
    cards.assign(T, {0, 0, 0, 0});
    rep(i,0,T) {
        scanf("%d %d", &cards[i].buy, &cards[i].sell);
        cards[i].tbuy = cards[i].buy*(2-deck[i]);
        cards[i].tsell = cards[i].sell*deck[i];
    }
    sort(all(cards), [](card a, card b) {
        return a.tbuy+a.tsell < b.tbuy+b.tsell;
    });
    ll res = 0;
    rep(i,0,K) {
        res -= cards[i].tbuy;
    }
    rep(i, K, T)
        res += cards[i].tsell;
    printf("%lld\n", res);
}
