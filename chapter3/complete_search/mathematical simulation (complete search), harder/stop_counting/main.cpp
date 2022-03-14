#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n; scanf("%d", &n);
	vector<ll> A(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%lld", &A[i]);
	vector<ll> presum(n, A[0]);
	for (int i = 1; i < n; i++)
		presum[i] = A[i] + presum[i-1];
	vector<ll> postsum(n, A[n-1]);
	for (int i = n-2; i >= 0; i--)
		postsum[i] = A[i] + postsum[i+1];
	long double res = 0;
	for (int i = 0; i < n; i++)
		res = max(res, (long double)presum[i]/(i+1));
	for (int i = n-1; i >= 0; i--)
		res = max(res, (long double)postsum[i]/(n-i));
	printf("%.9Lf\n", res);
}	
