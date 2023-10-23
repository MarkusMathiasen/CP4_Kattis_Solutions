#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

typedef uint64_t ull;
struct H {
    ull x; H(ull x=0) : x(x) {}
    H operator+(H o) { return x + o.x + (x + o.x < x); }
    H operator-(H o) { return *this + ~o.x; }
    H operator*(H o) { auto m = (__uint128_t)x * o.x;
        return H((ull)m) + (ull)(m >> 64); }
    ull get() const { return x + !~x; }
    bool operator==(H o) const { return get() == o.get(); }
    bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)

struct HashInterval {
    vector<H> ha, pw;
    HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
        pw[0] = 1;
        rep(i,0,sz(str))
            ha[i+1] = ha[i] * C + str[i],
                    pw[i+1] = pw[i] * C;
    }
    H hashInterval(ll a, ll b) { // hash [a, b)
        return ha[b] - ha[a] * pw[b - a];
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; ll Q; cin >> s >> Q;
    HashInterval h(s);
    while (Q--) {
        ll a, b; cin >> a >> b;
        ll low = 1, high = sz(s)-max(a, b)+1;
        while (low < high) {
            ll mid = (low+high)/2;
            if (h.hashInterval(a, a+mid) == h.hashInterval(b, b+mid))
                low = mid+1;
            else high = mid;
        }
        printf("%lld\n", low-1);
    }
}
