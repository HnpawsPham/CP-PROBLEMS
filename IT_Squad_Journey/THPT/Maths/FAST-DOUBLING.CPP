#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define pll pair<ll, ll>
#define fi first

// tính fibonacci chuẩn O(log n)
const ll MOD = 1e9 + 7;

pll fibo(ll n) {
    if(n == 0) return {0, 1};

    auto [f1, f2] = fibo(n / 2);
    ll l = (f1 * ((2 * f2 % MOD - f1 + MOD) % MOD)) % MOD;      // f1 x (2 x f2 - f1)
    ll r = (f1 * f1 + f2 * f2) % MOD;                           // f1^2 + f2^2
     
    if(n & 1) return {r, (l + r) % MOD}; 
    return {l, r};       
}

ll calc(ll n) {
    return fibo(n).fi;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout<<calc(1e12);
    return 0;
}