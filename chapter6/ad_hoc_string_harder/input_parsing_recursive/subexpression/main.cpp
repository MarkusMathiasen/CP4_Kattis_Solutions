#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T, cnt;
unordered_map<ll, ll> dp;
vi match;
string s;

const ll p = 131;
const ll q = 151;
const ll M = 1e9+7;
vi P, Q;
vi ha1, ha2;

ll has(ll left, ll right) {
	ll a = (((ha1[right+1] - ha1[left]*P[right-left+1])%M)+M)%M;
	ll b = (((ha2[right+1] - ha2[left]*Q[right-left+1])%M)+M)%M;
	return a*M+b;
}

string calc(ll& i) {
	ll start = i;
	ll len = 1;
	// read node name
	while (i+len < sz(s) && isalpha(s[i+len])) len++;
	string res = s.substr(i, len);
	i += len;
	// find end of node
	ll end = i < sz(s) && s[i] == '(' ? match[i] : i-1;
	ll h = has(start, end);
	// check if seen before
	if (dp.count(h)) {
		i = end+1;
		return to_string(dp[h]);
	}
	// if not, calculate node
	ll this_cnt = cnt++;
	if (i < sz(s) && s[i] == '(') {
		i++;
		string a = calc(i);
		if (s[i] != ',')
			assert(false);
		i++;
		string b = calc(i);
		assert(s[i] == ')');
		i++;
		res += "(" + a + "," + b + ")";
	}
	dp[h] = this_cnt;
	return res;
}

int main() {
	ll x = 1, y = 1;
	rep(i, 0, (ll)1e6) {
		P.push_back(x);
		Q.push_back(y);
		x = (x*p)%M;
		y = (y*q)%M;
	}
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cnt = 1;
		dp.clear();
		cin >> s;
		// prepare hashes
		ha1.assign(sz(s)+1, 0);
		ha2.assign(sz(s)+1, 0);
		rep(i, 0, sz(s))
			ha1[i+1] = (ha1[i]*p+s[i])%M,
			ha2[i+1] = (ha2[i]*q+s[i])%M;
		// prepare matchings
		match.assign(sz(s), -1);
		stack<ll> prev;
		rep(i, 0, sz(s)) {
			if (s[i] == '(') prev.push(i);
			if (s[i] == ')') {
				match[i] = prev.top();
				match[prev.top()] = i;
				prev.pop();
			}
		}
		ll pos = 0;
		string res = calc(pos);
		printf("%s\n", res.c_str());
	}
}
