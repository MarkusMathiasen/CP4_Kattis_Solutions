#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> hats(9, 0);
	for (int i = 0; i < 9; i++)
		scanf("%d", &hats[i]);
	for (int i = 0; i < 1<<9; i++) {
		int cnt = 0;
		int sum = 0;
		for (int j = 0; j < 9; j++)
			if (i & (1<<j))
				cnt++,
				sum += hats[j];
		if (cnt == 7 && sum == 100) {
			for (int j = 0; j < 9; j++)
				if (i & (1<<j))
					printf("%d\n", hats[j]);
			return 0;
		}
	}
}
