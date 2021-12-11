#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	while (N--) {
		vector<int> info(5, -1);
		for (int i = 0; i < 5; i++) {
			string s; cin >> s;
			if (s != "?")
				info[i] = stoi(s);
		}
		vector<int> A(5, -1);
		bool found = false;
		for (int b = 0; b <= 100 && !found; b++)
			for (int c = 0; c <= 100-b && !found; c++) {
				A[1] = b;
				A[2] = c;
				if (info[0] != -1)
					A[0] = max(info[0], b+c);
				else if (info[3] != -1)
					A[0] = min(100, b+c+info[3]);
				else 
					A[0] = b + c;
				A[3] = A[0] - A[1] - A[2];
				A[4] = A[1]*3 + A[2];
				bool correct = true;
				for (int i = 0; i < 5; i++)
					correct &= info[i] == A[i] || info[i] == -1;
				found |= correct;
			}
		assert(found);
		printf("%d %d %d %d %d\n", A[0], A[1], A[2], A[3], A[4]);
	}
}
