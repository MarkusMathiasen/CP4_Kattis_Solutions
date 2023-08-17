#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b%a, a);
}

int main() {
    long long a, b; scanf("%lld/%lld", &a, &b);
    a -= 32*b;
    a *= 5;
    b *= 9;
    long long c = gcd(a, b);
    a /= c, b /= c;
    printf("%lld/%lld\n", a, b);
}
