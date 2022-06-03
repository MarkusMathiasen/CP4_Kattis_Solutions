#include <bits/stdc++.h>
using namespace std;

int arr[2][1000000];
int n, res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	res = 0;
	for (int j = 0; j < 2; j++)
		for (int i = 0; i < n; i++)
			cin >> arr[j][i];
	for (int j = 0; j < 2; j++) {
		int curr = 0;
		for (int i = 0; i < n; i++) {
			if (arr[j][i] < curr)
				res = max(res, arr[j][i]);
			else if (arr[j][i] == curr)
				curr = 0;
			else
				res = max(res, curr),
				curr = arr[j][i];
		}
		res = max(res, curr);
	}
	printf("%d\n", res);
}
