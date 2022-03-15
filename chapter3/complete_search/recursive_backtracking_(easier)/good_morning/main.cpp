#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph = {
	{},
	{2, 4},
	{3, 5},
	{6},
	{5, 7},
	{6, 8},
	{9},
	{8},
	{9, 0},
	{}
};
vector<int> nums;

void genNums(int pos, int fuel, int num) {
	if (fuel == 0) {
		nums.push_back(num);
		return;
	}
	genNums(pos, fuel-1, num*10 + pos);
	for (int x : graph[pos])
		genNums(x, fuel, num);
}

int main() {
	for (int fuel = 1; fuel <= 4; fuel++)
		genNums(1, fuel, 0);
	int T; scanf("%d", &T);
	while (T--) {
		int k; scanf("%d", &k);
		int res = 0;
		for (int x : nums)
			if (abs(k-x) < abs(k-res))
				res = x;
		printf("%d\n", res);
	}
}
