#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b; cin >> a >> b;
    if (a % 2 == 1){
        cout << 0 << endl;
        return 0;
    }
    long long result = a/2;
    while(--b){
        result *= result;
        result %= a;
    }
    cout << result << endl;
}
