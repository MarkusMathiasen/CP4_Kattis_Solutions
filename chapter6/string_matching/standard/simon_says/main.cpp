#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T; cin >> T;
	string s; getline(cin, s);
	while (T--) {
		getline(cin, s);
		string sub = s.substr(0, 10);
		for (char& c : sub)
			c = tolower(c);
		if (sub == "simon says")
			printf("%s\n", s.substr(11).c_str());
	}
}
