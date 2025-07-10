#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'
#define vb vector<bool>
#define vi vector<int>

int n, m, k;
const ll MOD = 1e9 + 7;
const int sz = 2e5 + 5;
ll fact[sz], inv_fact[sz];

ll ppow(ll a, ll b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);

    if(b & 1) return 1LL * half * half % MOD * a % MOD;
    return 1LL * half * half % MOD;
}

void init_fact(){
    fact[0] = 1;

    for(int i = 1; i < sz; i++)
        fact[i] = fact[i - 1] * i % MOD;
    
    inv_fact[sz - 1] = ppow(fact[sz - 1], MOD - 2);

    for(int i = sz - 1; i > 0; i--)
        inv_fact[i - 1] = inv_fact[i] * i % MOD;
    return;
}

ll C(ll n, ll k){
    if(k < 0 || k > n) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

ll calc(int a, int b, int x, int y){
    return C(x - a + y - b, x - a);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    int maxn = min(n, 1000);
    int maxm = min(m, 1000);
    vector<vb> a(maxn, vb(maxm, 0));

    while(k--){
        int u, v;
        cin>>u>>v;
        a[u - 1][v - 1] = 1;
    }
    if(a[0][0]) return cout<<0, 0;

    vector<vi> dp(maxn, vi(maxm, 0));
    dp[0][0] = 1;

    for(int i = 1; i < maxn; i++) 
        if(!a[i][0]) dp[i][0] = dp[i - 1][0];

    for(int j = 1; j < maxm; j++) 
        if(!a[0][j]) dp[0][j] = dp[0][j - 1];

    for(int i = 1; i < maxn; i++)
        for(int j = 1; j < maxm; j++){
            if(a[i][j]) continue;

            if(!a[i - 1][j])
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD; 

            if(!a[i][j - 1]) 
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
        }

    init_fact();
    if(n <= maxn && m <= maxm) 
        return cout<<dp[n - 1][m - 1], 0;

    ll res = 0;

    for(int j = 0; j < maxm; j++){
        ll tmp = calc(1001, j + 1, n, m); 
        res = (res + dp[999][j] * tmp % MOD) % MOD;
    }

    for(int i = 0; i < maxn; i++){
        ll tmp = calc(i + 1, 1001, n, m); 
        res = (res + dp[i][999] * tmp % MOD) % MOD;
    }
    cout<<res;
    return 0;
}