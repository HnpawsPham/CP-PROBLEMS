#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1000000007
#define el "\n"

ll n, p;

ll ppow(ll a, ll b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);
    if(b % 2) return (half * half * a) % MOD;
    return (half * half) % MOD;
}

int main(){
    // freopen("CALC.INP", "r", stdin);
    // freopen("CALC.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>p>>n;
    ll res = 0;
    ll d1 = (ppow(p, n + 1) - 1 + MOD) % MOD;
    ll d2 = ppow(p - 1, MOD - 2);

    res = (d1 * d2) % MOD;
    cout<<res;
    return 0;
}