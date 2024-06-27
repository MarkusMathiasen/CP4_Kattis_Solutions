#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

typedef uint64_t ull;
typedef ull H;
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)
H hashVector(vi& s){H h{}; for(ll c:s) h=h*C+c;return h;}

string s;
ll n, res = 0;
set<H> H1, H2;
vector<ll> pows;

pair<ll,H> parse(ll i, set<H>& hashes) {
	if (isdigit(s[i])) {
		ll len = 1;
		while (i+len < sz(s) && isdigit(s[i+len])) len++;
		ll x = stoll(s.substr(i, len));
		hashes.insert(pows[x-1]);
		return {i+len,pows[x-1]};
	}
	H h1, h2;
	tie(i,h1) = parse(i+1, hashes);
	tie(i,h2) = parse(i+1, hashes);
	hashes.insert(h1+h2);
	return {i+1,h1+h2};
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> s;
	pows.assign(n+1, 1);
	rep(i, 1, sz(pows)) pows[i] = pows[i-1]*C;
	parse(0, H1);
	cin >> s;
	parse(0, H2);
	for (H h : H1) res += H2.count(h);
	printf("%lld\n", res);
}
