#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'

int t, n;
const int maxn = 1e7 + 5;
const ll MOD = 998244353;
int d[maxn];

void sieve(){
    for(int i = 2; i < maxn; i++) d[i] = i;

    for(int i = 2; i < sqrt(maxn); i++)
        if(d[i] == i)
            for(int j = i * i; j < maxn; j+=i)
                d[j] = i;
    return;
}

int cntdiv(ll x){
    int res = 1;

    while(x > 1){
        int i = d[x];
        int cnt = 0;

        while(x % i == 0){
            cnt++;
            x /= i;
        }
        res = res * (cnt + 1);
    }
    return res;
}

ll ppow(ll a, int b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);
    
    if(b & 1) return half * half % MOD * a % MOD;
    return half * half % MOD;
}

ll sol(){
    int m = cntdiv(n);
    ll res = ppow(n, m / 2);

    if(m & 1) res = res * (ll)sqrt(n) % MOD;
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    sieve();

    while(t--){
        cin>>n;
        cout<<sol()<<el;
    }

    return 0;
}

// 3
// 5
// 10
// 2986178