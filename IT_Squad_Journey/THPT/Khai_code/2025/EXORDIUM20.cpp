#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define MOD 1000000007

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    
    if (n == 0) {
        cout << 0;
        return 0;
    }

    ll a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        ll c = (a + b) % MOD;
        a = b;
        b = c;
    }

    cout << b << el;
    return 0;
}