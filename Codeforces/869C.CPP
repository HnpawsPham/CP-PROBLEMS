#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const ll MOD = 998244353;
const int maxn = 5005;
ll fact[maxn], invfact[maxn];

ll ppow(ll a, ll b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);
    if(b & 1) return 1LL * half * half % MOD * a % MOD;
    return 1LL * half * half % MOD;
}

void calc_fact(){
    fact[0] = 1;
    for(int i = 1; i < maxn; i++)
        fact[i] = fact[i - 1] * i % MOD;
    
    invfact[maxn - 1] = ppow(fact[maxn - 1], MOD - 2);
    for(int i = maxn - 2; i >= 0; i--)
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    return;
}

ll C(int n, int k){
    return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}

ll calc(int a, int b){
    ll res = 0;
    for(int i = 0; i <= min(a, b); i++)
        res = (res + C(a, i) * C(b, i) % MOD * fact[i] % MOD) % MOD;
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int a, b, c;
    cin>>a>>b>>c;
    
    calc_fact();

    ll res = 1;
    res = res * calc(a, b) % MOD;
    res = res * calc(b, c) % MOD;
    res = res * calc(a, c) % MOD;
    cout<<res;
    return 0;
}