#include <bits/stdc++.h>
using namespace std;

int main() {
	int row = 0, col = 0, dia1 = 0, dia2 = 0, cnt = 0;
	bool invalid = false;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			char c; scanf(" %c", &c);
			if (c == '.')
				continue;
			cnt++;
			invalid |= row&(1<<i);
			row |= 1<<i;
			invalid |= col&(1<<j);
			col |= 1<<j;
			invalid |= dia1&(1<<(i+j));
			dia1 |= 1<<(i+j);
			invalid |= dia2&(1<<(7+i-j));
			dia2 |= 1<<(7+i-j);
		}
	invalid |= cnt != 8;
	printf(invalid ? "invalid\n" : "valid\n");
}
