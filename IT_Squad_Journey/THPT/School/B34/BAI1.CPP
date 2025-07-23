#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define el '\n'

const ll MOD = 2023;

int main(){
    freopen("BAI1.INP", "r", stdin);
    freopen("BAI1.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin>>n;
    ll x = n % MOD;
    ll y = (3 * x % MOD + 1) % MOD;

    ll res = (x * y) % MOD;
    if (n % 2 == 0) res = (res * ((MOD + 1) / 2)) % MOD; 
    else res = (res * ((MOD + 1) / 2)) % MOD;

    cout << res;
    return 0;
}