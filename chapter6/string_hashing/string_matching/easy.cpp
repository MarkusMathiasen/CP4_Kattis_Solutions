#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string pat, s;
	while (getline(cin, pat), getline(cin, s)) {
		size_t pos = 0;
		while (pos = s.find(pat, pos), pos != string::npos)
			printf("%ld ", pos++);
		printf("\n");
	}
}
