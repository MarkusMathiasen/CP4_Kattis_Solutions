#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	while (cin >> s, s != "0") {
		int lowers = 0;
		for (char c : s)
			lowers += (bool)islower(c);
		if (!lowers) {
			printf("no WFF possible\n");
			continue;
		}
		for (char c : s) {
			if (lowers <= 1)
				break;
			if (c == 'K' || c == 'A' || c == 'C' || c == 'E')
				printf("%c", c), lowers--;
		}
		for (char c : s)
			if (c == 'N')
				printf("%c", c);
		for (char c : s)
			if (islower(c))
				if (lowers > 1)
					lowers--;
				else
					printf("%c", c);
		printf("\n");
	}
}
