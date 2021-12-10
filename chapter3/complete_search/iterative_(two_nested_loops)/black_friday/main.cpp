#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<int> freq(7, 0);
	vector<int> rolls(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &rolls[i]),
		freq[rolls[i]]++;
	for (int i = 6; i > 0; i--)
		if (freq[i] == 1) {
			for (int j = 0; j < n; j++)
				if (rolls[j] == i)
					printf("%d\n", j+1);
			return 0;
		}
	printf("none\n");
}
