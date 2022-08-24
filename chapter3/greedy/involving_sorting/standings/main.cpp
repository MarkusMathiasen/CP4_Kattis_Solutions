#include <bits/stdc++.h>
using namespace std;

int r[100000];
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		for (int i = 0; i < N; i++)
			cin >> s >> r[i];
		sort(r, r+N);
		long long res = 0;
		for (int i = 0; i < N; i++)
			res += (long long)abs(i+1 - r[i]);
		printf("%lld\n", res);
	}
}
