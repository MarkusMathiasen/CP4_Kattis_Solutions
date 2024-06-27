#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

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

struct MyMultiset {
	map<ll, ll> A;
	void insert(ll x) {
		A[x]++;
	}
	void erase(ll x) {
		assert(A[x] > 0);
		A[x]--;
		if (A[x] == 0) A.erase(x);
	}
	ll size() {
		return A.size();
	}
	ll min() {
		return A.begin()->first;
	}
	ll count(ll x) {
		return A[x];
	}
};

ll n, req;
vector<string> A(100, "");
const ll offset = 5;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	bool first = true;
	while ((cin >> n), n>0) {
		req = n/2 + 1;
		if (!first) printf("\n");
		first = false;
		rep(i, 0, (ll)n) (cin >> A[i]);
		if (n == 1) {
			printf("%s\n", A[0].c_str());
			continue;
		} else if (n == 2) {
			sort(A.begin(), A.begin()+2);
			if (sz(A[0]) >= sz(A[1])) printf("%s\n", A[0].c_str());
			if (sz(A[1]) >= sz(A[0])) printf("%s\n", A[1].c_str());
			continue;
		}
		string sa_string = "";
		rep(i, 0, n) {
			for (char c : A[i])
				sa_string.push_back(c + offset);
			sa_string.push_back((char)(i+1));
		}
		unordered_map<ll, ll> get_idx;
		ll idx = 0;
		rep(i, 0, sz(sa_string)) {
			if (sa_string[i] <= 100) idx++;
			else get_idx[i] = idx;
		}
		SuffixArray sa(sa_string);
		ll low = 0;
		while (sa_string[sa.sa[low]] <= 100) low++;
		MyMultiset S, lcps;
		vector<string> res;
		ll res_length = 1;
		bool changed = true;
		rep(high, low, sz(sa.sa)) {
			if (high != low)
				lcps.insert(sa.lcp[high]);
			idx = get_idx[sa.sa[high]];
			S.insert(idx);
			while (S.size() > req || S.count(get_idx[sa.sa[low]]) > 1) {
				lcps.erase(sa.lcp[low+1]);
				S.erase(get_idx[sa.sa[low]]);
				low++;
			}
			if (S.size() >= req) {
				ll m = lcps.min();
				if (m < res_length) changed = true;
				if (m > res_length) res.clear(), res_length = m, changed=true;
				if (m >= res_length && changed) {
					res.push_back(sa_string.substr(sa.sa[high], m));
					changed = false;
				}
			}
		}
		rep(i, 0, sz(res)-1) assert(sz(res[i]) == sz(res[i+1]));
		if (res.empty())
			printf("?\n");
		else
			for (string& s : res) {
				for (char c : s) printf("%c", (char)(c-offset));
				printf("\n");
			}
	}
}
