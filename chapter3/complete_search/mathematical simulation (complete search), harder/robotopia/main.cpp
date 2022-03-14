#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	while (n--) {
		int l1, a1, l2, a2, lt, at; scanf("%d%d%d%d%d%d", &l1, &a1, &l2, &a2, &lt, &at);
		lt -= l1 + l2;
		at -= a1 + a2;
		int solutions = 0;
		int s1, s2;
		for (int i = 0; i <= 10000; i++) {
			int l_left = lt - l1*i;
			int a_left = at - a1*i;
			if (l_left < 0 || a_left < 0)
				break;
			if (a_left % a2 == 0 && l_left % l2 == 0
					&& a_left / a2 == l_left / l2)
				solutions++, s1 = i, s2 = a_left/a2;
		}
		if (solutions == 1)
			printf("%d %d\n", s1+1, s2+1);
		else
			printf("?\n");
	}
}
