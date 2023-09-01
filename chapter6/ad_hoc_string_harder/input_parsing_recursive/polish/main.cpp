#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll t = 0;
string s;

queue<string> simplify(queue<string>& tokens) {
	queue<string> res;
	string first = tokens.front(); tokens.pop();
	res.push(first);
	if (first != "+" && first != "-" && first != "*")
		return res;
	queue<string> p1 = simplify(tokens);
	queue<string> p2 = simplify(tokens);
	if (sz(p1) == 1 && sz(p2) == 1 && isdigit(p1.front().back()) && isdigit(p2.front().back())) {
		ll a = stoi(p1.front());
		ll b = stoi(p2.front());
		res.pop();
		if (first == "+") res.push(to_string(a+b));
		else if (first == "-") res.push(to_string(a-b));
		else if (first == "*") res.push(to_string(a*b));
		else assert(false);
		return res;
	}
	while (!p1.empty())
		res.push(p1.front()),
		p1.pop();
	while (!p2.empty())
		res.push(p2.front()),
		p2.pop();
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (getline(cin, s) && s != "") {
		printf("Case %lld:", ++t);
		queue<string> tokens;
		stringstream ss(s);
		string x;
		while (ss >> x) tokens.push(x);
		queue<string> res = simplify(tokens);
		while (!res.empty())
			printf(" %s", res.front().c_str()),
			res.pop();
		printf("\n");
	}
}
