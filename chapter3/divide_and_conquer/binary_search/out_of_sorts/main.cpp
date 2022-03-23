#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, m, a, c, x0; scanf("%lld%lld%lld%lld%lld", &n, &m, &a, &c, &x0);
	vector<ll> A(n, 0);
	A[0] = ((a*x0)%m+c)%m;
	for (int i = 1; i < n; i++)
		A[i] = ((a*A[i-1])%m+c)%m;
	int res = 0;
	for (ll x : A) {
		int low = 0, high = n-1;
		while (low < high) {
			int mid = (low+high)/2;
			if (A[mid] == x)
				low = high = mid;
			else if (x < A[mid])
				high = mid-1;
			else
				low = mid+1;
		}
		res += A[low] == x;
	}
	printf("%d\n", res);
}
