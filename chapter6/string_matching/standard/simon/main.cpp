#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T; cin >> T;
	string s; getline(cin, s);
	while (T--) {
		getline(cin, s);
		if (s.substr(0, 10) == "simon says" && (int)s.size() > 10)
			printf("%s", s.substr(11).c_str());
		printf("\n");
	}
}
