#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s; cin >> s;
	int n = count(s.begin(), s.end(), '(');
	set<string> res;
	for (int comb = 1; comb < (1<<n); comb++) {
		int starts = 0;
		stack<bool> ends;
		string ns = "";
		for (char c : s) {
			if (c == '(') {
				if (!((1<<starts)&comb)) {
					ns.push_back(c);
					ends.push(false);
				} else
					ends.push(true);
				starts++;
			}
			else if (c == ')') {
				if (!ends.top())
					ns.push_back(c);
				ends.pop();
			}
			else
				ns.push_back(c);
		}
		res.insert(ns);
	}
	for (const string& x : res)
		printf("%s\n", x.c_str());
}
