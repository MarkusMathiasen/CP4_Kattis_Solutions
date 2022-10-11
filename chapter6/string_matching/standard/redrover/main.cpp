#include <bits/stdc++.h>
using namespace std;

int count_substring(string& s, string& sub) {
	size_t i = 0;
	int res = 0;
	while(i = s.find(sub, i), i != string::npos)
		res++, i += sub.size();
	return res;
}

int main() {
	string s; cin >> s;
	int res = s.size();
	for (int i = 0; i < (int)s.size(); i++)
		for (int j = i+2; j < (int)s.size(); j++) {
			string sub = s.substr(i, j-i);
			res = min(res,
			(int)s.size() - (int)count_substring(s, sub)*(int)(sub.size()-1)+(int)sub.size());
		}
	printf("%d\n", res);
}
