#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll S;
vector<string> syl;

vi decompose_word(string& word) {
	vector<set<ll>> dp(sz(word)+1, set<ll>());
	dp[0].insert(0);
	rep(i, 0, sz(word)) if (sz(dp[i]) > 0) for (string s : syl)
		if (sz(s) + i <= sz(word) && word.substr(i, sz(s)) == s)
			for (ll x : dp[i]) if (x+1 <= 7)
				dp[i+sz(s)].insert(x+1);
	vi res;
	for (ll x : dp[sz(word)])
		res.push_back(x);
	if (sz(res) == 0)
		res.push_back(100);
	return res;
}

bool decompose_line(string& line, ll goal) {
	stringstream ss(line);
	string word;
	vector<vi> v;
	while (ss >> word)
		v.push_back(decompose_word(word));
	ll sum = 0;
	if (sz(v) > goal) return false;
	if (sz(v) > 0) for (ll a : v[0]) {
		sum += a;
		if (sz(v) > 1) for(ll b : v[1]) {
			sum += b;
			if (sz(v) > 2) for(ll c : v[2]) {
				sum += c;
				if (sz(v) > 3) for(ll d : v[3]) {
					sum += d;
					if (sz(v) > 4) for(ll e : v[4]) {
						sum += e;
						if (sz(v) > 5) for(ll f : v[5]) {
							sum += f;
							if (sz(v) > 6) for (ll g : v[6]) {
								sum += g;
								if (sz(v) == 7 && sum == goal) return true;
								sum -= g;
							}
							if (sz(v) == 6 && sum == goal) return true;
							sum -= f;
						}
						if (sz(v) == 5 && sum == goal) return true;
						sum -= e;
					}
					if (sz(v) == 4 && sum == goal) return true;
					sum -= d;
				}
				if (sz(v) == 3 && sum == goal) return true;
				sum -= c;
			}
			if (sz(v) == 2 && sum == goal) return true;
			sum -= b;
		}
		if (sz(v) == 1 && sum == goal) return true;
		sum -= a;
	}
	return false;
}

int main() {
	// Read input
	cin.tie(0)->sync_with_stdio(0);
	ll S; cin >> S;
	syl.assign(S, "");
	rep(i, 0, S) cin >> syl[i];
	string s; getline(cin, s);

	bool res = true;
	// First line
	getline(cin, s);
	res &= decompose_line(s, 5);
	// Second line
	getline(cin, s);
	res &= decompose_line(s, 7);
	// Third line
	getline(cin, s);
	res &= decompose_line(s, 5);
	// Print result
	printf(res ? "haiku\n" : "come back next year\n");
}
