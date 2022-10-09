#include <bits/stdc++.h>
using namespace std;

int cnt(string& s, string& sub) {
	int res = 0;
	size_t idx = 0;
	while (idx = s.find(sub, idx), idx != string::npos)
		res++, idx++;
	return res;
}

int main() {
	string sub, s;
	while (cin >> sub >> s) {
		printf("%d", cnt(s, sub));
		int res = 0;
		set<string> subs;
		for (int i = 0; i < (int)sub.size(); i++)
			subs.insert(sub.substr(0, i) + sub.substr(i+1));
		for (string sub : subs)
			res += cnt(s, sub);
		printf(" %d", res);
		res = 0;
		subs.clear();
		for (int i = 0; i <= (int)sub.size(); i++)
			for (char c : "ATGC")
				subs.insert(sub.substr(0, i) + c + sub.substr(i));
		for (string sub : subs)
			res += cnt(s, sub);
		printf(" %d\n", res);
	}
}
