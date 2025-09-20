#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;
const int maxn = 2 * 2027;
const int maxp = 2e6 + 5;
const ll MOD = 998244353;
bitset<maxp> nprime;
int a[maxn];
ll fact[maxp], invfact[maxp], dp[maxn][maxn];
vector<pii> p, prime;

void sieve(){
    nprime[0] = nprime[1] = 1;
    for(int i = 2; i <= sqrt(maxp); i++)
        if(!nprime[i])
            for(int j = i * i; j < maxp; j+=i)
                nprime[j] = 1;
    return;
}

ll ppow(int a, int b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);
    if(b & 1) return half * half % MOD * a % MOD;
    return half * half % MOD;
}

void calc_fact(){
    fact[0] = 1;
    for(int i = 1; i < maxp; i++)
        fact[i] = fact[i - 1] * i % MOD;
    invfact[maxp - 1] = ppow(fact[maxp - 1], MOD - 2);

    for(int i = maxp - 2; i >= 0; i--)
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < 2 * n; i++) cin>>a[i];
    sort(a, a + 2 * n);

    sieve();
    calc_fact();

    for(int i = 0; i < 2 * n; i++){
        if(p.empty() || p.back().fi != a[i]) 
            p.push_back({a[i], 1});
        else p.back().se++;        
    }

    for(auto x : p)
        if(!nprime[x.fi]) prime.push_back(x);

    memset(dp, -1, sizeof(dp));
    int sz = prime.size();
    for(int i = sz; i >= 0; i--)
        for(int j = 0; j <= n; j++){
            if(i == sz) dp[i][j] = (j == 0);
            else {
                ll res = invfact[prime[i].se] * dp[i + 1][j] % MOD;
                if(j > 0) res = (res + invfact[prime[i].se - 1] * dp[i + 1][j - 1]) % MOD;
                dp[i][j] = res;
            }
        }

    ll res = dp[0][n];
    for(auto x : p)
        if(nprime[x.fi]) res = res * invfact[x.se] % MOD;

    res = res * fact[n] % MOD;
    cout<<res;
    return 0;
}