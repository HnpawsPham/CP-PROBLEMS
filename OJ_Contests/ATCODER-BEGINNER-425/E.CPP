#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc, MOD;
const int maxn = 1e5 + 5;
ll fact[maxn], invfact[maxn];

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

    invfact[maxn - 1] = ppow(fact[maxn - 1], MOD - 2);
    for(int i = maxn - 2; i >= 0; i--)
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    return;
}

ll sol(){
    int n;
    cin>>n;
    int a[n];
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        sum += a[i];
    }

    ll res = fact[sum];
    for(int x : a)
        res = res * invfact[x] % MOD;

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc>>MOD;
    calc_fact();
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}