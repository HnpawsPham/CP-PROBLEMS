#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second

const ll MOD = 998244353;
const int maxn = 2e5 + 5;
int tc;
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
    if(k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}

ll calc(int a, int b){
    if(b == 0) return (a == 0 ? 1 : 0);
    if(b < 1 || b > a) return 0;
    return C(a - 1, b - 1);
}

ll sol(){
    int n, k;
    cin>>n>>k;
    
    int a = n / 3, b = (n / 3) + (n % 3 > 0), c = (n / 3) + (n % 3 >= 2);
    
    ll res = 0;
    int maxr = min(b + c, a + 1);
    
    for(int i = 1; i <= maxr; i++){
        int m = i - 1;
        ll t1 = calc(b, (i + 1) / 2) * calc(c, i / 2) % MOD;
        ll t2 = calc(b, i / 2) * calc(c, (i + 1) / 2) % MOD;
        ll cnt = (t1 + t2) % MOD;
        
        ll tmp = C(b + c + 1 - m, a - m);
        res = (res + cnt * tmp % MOD) % MOD;
    }
    
    res = res * fact[a] % MOD;
    res = res * fact[b] % MOD;
    res = res * fact[c] % MOD;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
	cin>>tc;
	calc_fact();
	while(tc--){
        cout<<sol()<<el;
	}
    return 0;
}
