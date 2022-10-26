#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	int res = 0;
	while (n--) {
		string s; cin >> s;
		for (char& c : s)
			c = tolower(c);
		res += s.find("rose") != string::npos || s.find("pink") != string::npos;
	}
	if (res)
		printf("%d\n", res);
	else
		printf("I must watch Star Wars with my daughter\n");
}
