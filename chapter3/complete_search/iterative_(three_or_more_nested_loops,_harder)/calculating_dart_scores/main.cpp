#include <bits/stdc++.h>
using namespace std;

string nice(int x) {
	switch (x) {
		case 1: return "single";
		case 2: return "double";
		case 3: return "triple";
		default: throw x;
	}
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= 20; i++)
		for (int mi = 1; mi <= 3; mi++)
			for (int j = 1; j <= 20; j++)
				for (int mj = 1; mj <= 3; mj++)
					for (int k = 1; k <= 20; k++)
						for (int mk = 1; mk <= 3; mk++)
							if (i*mi == n) {
								printf("%s %d\n", nice(mi).c_str(), i);
								return 0;
							}
							else if (i*mi + j*mj == n) {
								printf("%s %d\n", nice(mi).c_str(), i);
								printf("%s %d\n", nice(mj).c_str(), j);
								return 0;
							}
							else if (i*mi + j*mj + k*mk == n) {
								printf("%s %d\n", nice(mi).c_str(), i);
								printf("%s %d\n", nice(mj).c_str(), j);
								printf("%s %d\n", nice(mk).c_str(), k);
								return 0;
							}
	printf("impossible\n");
}
