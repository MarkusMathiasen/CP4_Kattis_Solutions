#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> res;
	for (int i = 1; i <= 5; i++) {
		string s; cin >> s;
		if (s.find("FBI") != string::npos)
			res.push_back(i);
	}
	if (!res.size())
		printf("HE GOT AWAY!");
	else
		for (int x : res)
			printf("%d ", x);
	printf("\n");
}
