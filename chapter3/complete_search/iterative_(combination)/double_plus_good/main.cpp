#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

set<ll> res;

int main() {
	vector<string> nums;
	string s;
	while (getline(cin, s, '+'))
		nums.push_back(s);
	int p = nums.size()-1;
	for (int comb = 0; comb < (1<<p); comb++) {
		vector<string> newNums;
		newNums.push_back(nums[0]);
		for (int i = 0; i < p; i++)
			if (comb&(1<<i))
				newNums.back() += nums[i+1];
			else
				newNums.push_back(nums[i+1]);
		ll sum = 0;
		for (string& x : newNums)
			sum += stoll(x);
		res.insert(sum);
	}
	printf("%ld\n", res.size());
}
