#include <bits/stdc++.h>
using namespace std;

set<int> primes;
int n, b;
int sum = 0;

bool isPrime(int x) {
	for (int p : primes)
		if (x%p == 0)
			return false;
	return true;
}

int main() {
	primes.insert(2);
	for (int i = 3; i < 1300; i++)
		if (isPrime(i))
			primes.insert(i);
	scanf("%d%d", &n, &b);
	vector<int> nums(n, 0);
	for (int i = 0; i < n; i++)
		nums[i] = i+1,
		sum += i+1;
	int pos = n-1;
	while (!primes.count(sum)) {
		sum++;
		nums[pos]++;
		pos--;
		if (pos < 0)
			pos = n-1;
	}
	if (nums[n-1] > b) {
		printf("impossible\n");
		return 0;
	}
	vector<vector<int>> matrix(n, vector<int>(n, 0));
	pos = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			matrix[i][j] = nums[(j+pos)%n];
		pos++;
	}
	for (auto r : matrix) {
		for (auto c : r) {
			printf("%d ", c);
		}
		printf("\n");
	}

}
