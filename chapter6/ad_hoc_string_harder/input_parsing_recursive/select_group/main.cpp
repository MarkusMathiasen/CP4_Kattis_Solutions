#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

map<string, set<string>> groups;

vector<string> tokens;
string line;

ll get_group(ll i, set<string>& res) {
	if (tokens[i] != "union" && tokens[i] != "intersection"
			&& tokens[i] != "difference") {
		for (string s : groups[tokens[i]])
			res.insert(s);
		return i;
	}
	set<string> res1, res2;
	ll j = get_group(i+1, res1);
	ll k = get_group(j+1, res2);
	if (tokens[i] == "union") {
		for (string s : res2) res1.insert(s);
		res = res1;
	}
	else if (tokens[i] == "intersection") {
		for (string s : res1)
			if (res2.count(s))
				res.insert(s);
	}
	else if (tokens[i] == "difference") {
		for (string s : res2)
			res1.erase(s);
		res = res1;
	}
	else assert(false);
	return k;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (getline(cin, line) && line != "") {
		stringstream ss(line);
		tokens.clear();
		string s;
		while (ss >> s)
			tokens.push_back(s);
		if (tokens[0] == "group")
			rep(i, 3, sz(tokens))
				groups[tokens[1]].insert(tokens[i]);
		else {
			set<string> res;
			get_group(0, res);
			for (string s : res)
				printf("%s ", s.c_str());
			printf("\n");
		}
	}
}
