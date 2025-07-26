#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'
#define vi vector<int>

const ll MOD = 1e9 + 7;
const int maxn = 1e5 + 5;
vector<ll> fact(maxn), inv_fact(maxn);

ll ppow(ll a, int b){
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

ll C(int n, int k){
    if(k > n) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<vi> pt(n);
    for(int i = 0; i < n; i++){
        int x, y;
        cin>>x>>y;
        pt[i] = {x, y};
    }

    calc_fact();

    unordered_map<int, vi> mp;
    for(const vi& v : pt)
        mp[v[1]].push_back(v[0]);
    
    int i = 0, m = mp.size();
    vector<ll> a(m);

    for(auto& [y, v] : mp){
        a[i] = C(v.size(), 2);
        i++;
    }
    
    ll sum = 0, d = 0;
    for(int i = 0; i < m; i++){
        sum = (sum + a[i]) % MOD;
        d += a[i] * a[i] % MOD;
    }
    ll res = (sum * sum % MOD - d + MOD) % MOD;
    res = res * ppow(2, MOD - 2) % MOD;
    cout<<res;
    return 0;
}
// 5
// 1 0  
// 2 0
// 3 0
// 2 2
// 3 2