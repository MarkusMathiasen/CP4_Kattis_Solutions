#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> digits(10, 0);
	string s; cin >> s;
	for (char c : s)
		digits[c-'0']++;
	int d = 1;
	for (int i = 2; i < 10; i++)
		if (digits[i] < digits[d])
			d = i;
	if (digits[0] < digits[d]) {
		printf("1");
		for (int i = 0; i < digits[0]+1; i++)
			printf("0");
	}
	else
		for (int i = 0; i < digits[d]+1; i++)
			printf("%d", d);
	printf("\n");
}
