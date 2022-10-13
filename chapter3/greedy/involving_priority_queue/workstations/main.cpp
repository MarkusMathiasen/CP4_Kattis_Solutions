#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main() {
	int n, m; scanf("%d%d", &n, &m);
	priority_queue<int, vector<int>, greater<int>> w, out;
	vector<ii> emp(n, ii());
	for (int i = 0; i < n; i++)
		scanf("%d%d", &emp[i].first, &emp[i].second);
	sort(emp.begin(), emp.end());
	int res = 0;
	for (auto [a,s] : emp) {
		while (!out.empty() && out.top() <= a)
			w.push(out.top()+m),
			out.pop();
		while (!w.empty() && w.top() < a)
			w.pop();
		if (!w.empty())
			w.pop();
		else
			res++;
		out.push(a+s);
	}
	printf("%d\n", n-res);
}
