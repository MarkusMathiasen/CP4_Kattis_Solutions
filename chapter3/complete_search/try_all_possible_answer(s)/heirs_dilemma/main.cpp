#include <bits/stdc++.h>
using namespace std;

int main() {
	int L, H; scanf("%d%d", &L, &H);
	int res = 0;
	for (int i = L; i <= H; i++) {
		bool valid = true;
		set<int> nums;
		for (char c : to_string(i)) {
			int d = c - '0';
			valid &= d != 0;
			if (!valid)
				break;
			nums.insert(d);
			valid &= i%d == 0;
		}
		valid &= nums.size() == 6l;
		res += valid;
	}
	printf("%d\n", res);
}
