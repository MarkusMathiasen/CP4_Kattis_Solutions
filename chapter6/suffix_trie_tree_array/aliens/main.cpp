#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

struct UF {
	vi e;
	UF(ll n) : e(n, -1) {}
	bool sameSet(ll a, ll b) { return find(a) == find(b); }
	ll size(ll x) { return -e[find(x)]; }
	ll find(ll x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(ll a, ll b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

struct SuffixArray {
	vi sa, lcp;
	SuffixArray(string& s, ll lim=256) { // or basic_string<ll>
		ll n = sz(s) + 1, k = 0, a, b;
		vi x(all(s)+1), y(n), ws(max(n, lim)), rank(n);
		sa = lcp = y, iota(all(sa), 0);
		for (ll j = 0, p = 0; p < n; j = max(1ll, j * 2), lim = p) {
			p = j, iota(all(y), n - j);
			rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
			fill(all(ws), 0);
			rep(i,0,n) ws[x[i]]++;
			rep(i,1,lim) ws[i] += ws[i - 1];
			for (ll i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
		}
		rep(i,1,n) rank[sa[i]] = i;
		for (ll i = 0, j; i < n - 1; lcp[rank[i++]] = k)
			for (k && k--, j = sa[rank[i] - 1];
					s[i + k] == s[j + k]; k++);
	}
};

const ll inf = 1e9;

int main() {
	cin.tie(0)->sync_with_stdio(0);
    ll m; string s;
    while (cin >> m >> s) {
        ll n = sz(s);
        if (m == 1) {
            printf("%lld %lld\n", n, 0);
            continue;
        }
        SuffixArray A(s);
        UF uf(n+1);
        vi order(n+1);
        rep(i, 0, n+1) order[i] = i;
        sort(all(order), [&](const ll a, const ll b) {
            return A.lcp[a] > A.lcp[b];
        });
        ll length = 0;
        for (ll i : order) {
            if (A.lcp[i] < length) break;
            if (i > 0 && A.lcp[i-1] >= A.lcp[i]) uf.join(i-1, i);
            if (i < n && A.lcp[i+1] >= A.lcp[i]) uf.join(i+1, i);
            if (uf.size(i)+1 >= m) length = A.lcp[i];
        }
        if (length == 0) printf("none\n");
        else {
            ll p = -1;
            rep(i, 0, n+1) if (uf.size(i)+1 >= m && A.lcp[i] >= length) {
                p = max(p, A.sa[i]);
                assert(i > 0);
                p = max(p, A.sa[i-1]);
            }
            //assert(p >= 0);
            printf("%lld %lld\n", length, p);
        }
    }
}