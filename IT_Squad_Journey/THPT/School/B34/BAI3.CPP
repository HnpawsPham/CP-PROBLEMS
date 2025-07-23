#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define el '\n'

const ll MOD = 1e9 + 7;
const int maxn = 1005;
ll fact[maxn], inv_fact[maxn];

ll ppow(ll a, ll b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);

    if(b & 1) return half * half % MOD * a % MOD;
    return half * half % MOD;
}

void calc_fact(){
    fact[0] = 1;
    for(int i = 1; i < maxn; i++)
        fact[i] = fact[i - 1] * i % MOD;

    inv_fact[maxn - 1] = ppow(fact[maxn - 1], MOD - 2);
    for(int i = maxn - 2; i >= 0; i--)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    return;
}

ll C(ll n, ll k){
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

int main(){
    freopen("BAI3.INP", "r", stdin);
    freopen("BAI3.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    calc_fact();
    cout<<C(n, k);
    return 0;
}