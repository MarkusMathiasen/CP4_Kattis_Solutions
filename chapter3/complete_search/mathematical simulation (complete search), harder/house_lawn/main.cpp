#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct mower {
	string name;
	ll p;
	mower(string name, ll p) : name(name), p(p) {}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll l, m; cin >> l >> m;
	string s; getline(cin, s);
	vector<mower> A;
	while (m--) {
		string name; getline(cin, name, ',');
		ll p; getline(cin, s, ','); p = stoll(s);
		ll c; getline(cin, s, ','); c = stoll(s);
		ll t; getline(cin, s, ','); t = stoll(s);
		ll r; getline(cin, s); r = stoll(s);
		if (c*t*10080ll >= l*(t+r))
			A.push_back(mower(name, p));
	}
	stable_sort(A.begin(), A.end(), [](const mower& a, const mower& b) {
		return a.p < b.p;
	});
	for (mower& x : A)
		if (x.p == A[0].p)
			cout << x.name << endl;
	if (!A.size())
		cout << "no such mower\n";
}
