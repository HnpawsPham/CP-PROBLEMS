#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

const int MOD = 1e9 + 7;
const int maxn = 1e5;
int n, m, k;

ll fact[maxn], inv_fact[maxn];

ll ppow(int a, int b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);
    
    if(b & 1) return half * half % MOD * a % MOD;
    return half * half % MOD;
}

void calc_fact(){
    fact[0] = fact[1] = 1;
    for(int i = 2; i < maxn; i++)
        fact[i] = fact[i - 1] * i % MOD;

    inv_fact[maxn - 1] = ppow(fact[maxn - 1], MOD - 2);
    for(int i = maxn - 1; i; i--)
        inv_fact[i - 1] = inv_fact[i] * i % MOD;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    calc_fact();

    ll comb = fact[n - 1] * inv_fact[k] % MOD * inv_fact[n - k - 1] % MOD;
    int res = comb * m % MOD * ppow(m - 1, n - k - 1) % MOD;
    cout<<res;
    return 0;
}