#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

// tính fibonacci chuẩn O(log n)
const ll MOD = 1e9 + 7;

ll calc(ll n) {
    if (n == 0) return 0;
    ll a = 0, b = 1;

    for (ll i = 63; i >= 0; --i) {
        if ((n >> i) == 0) continue;

        ll d = (a * ((2 * b % MOD - a + MOD) % MOD)) % MOD;
        ll e = (a * a + b * b) % MOD;

        if ((n >> i) & 1) {
            a = e;
            b = (d + e) % MOD;
        } 
        else {
            a = d;
            b = e;
        }
    }
    return a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout<<calc(1e12);
    return 0;
}