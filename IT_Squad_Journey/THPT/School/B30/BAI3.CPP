#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define el "\n"
#define MOD 1000000007

ll n, k;

ll fact(ll x) { 
    ll res = 1; 
    for (ll i = 2; i <= x; i++)
        res = (res * i) % MOD; 
    return res;
}

ll ppow(ll a, ll b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2) % MOD;

    if(b % 2) return (1LL * half * half * a) % MOD;
    return (1LL * half * half) % MOD;
}

int main(){
    freopen("BAI3.INP", "r", stdin);
    freopen("BAI3.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    if(k == 1) return cout<<n, 0;
    if(n == k) return cout<<1, 0;
    if(k > n) return cout<<0, 0;

    ll m = (fact(k) * fact(n - k)) % MOD;
    ll res = (fact(n) * ppow(m, MOD - 2)) % MOD;
    cout<<res;
    return 0;
}
