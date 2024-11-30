#include <bits/stdc++.h>
using namespace std;
#define el "\n"
using ll = unsigned __int64;

int t;
const int maxn = 205;
bool kngto[maxn];

void sieve(){
    kngto[0] = kngto[1] = 1;

    for(int i = 2; i < sqrt(maxn); i++){
        if(!kngto[i])
            for(int j = i + i; j < maxn; j+= i)
                kngto[j] = 1;
    }
    return;
}

ll ppow(ll a, ll b){
    if(b == 1) return a;
    if(b % 2 == 0) return ppow(a, b / 2) * ppow(a, b / 2);
    else return ppow(a, b / 2) * ppow(a, b / 2) * a;
}

int countPi(int x, int n){
    int res = 0;

    for(int i = 1;; i++){
        ll p = ppow(x, i);
        if(p > n) return max(res, 1);

        res += (n / p);
    }
}

void solve(){
    int n;
    cin>>n;

    ll res = 1;
    for(int i = 1; i <=n; i++){
        if(kngto[i]) continue;
        int pi = countPi(i, n);
        res *= ((ppow(i, pi + 1) - 1) / (i - 1));
    }
    cout<<res;
    return;
}

int main(){
    freopen(".\\txt\\BTVN.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    sieve();

    for(int i = 0; i < t - 1; i++){
        solve();
        cout<<el;
    }
    solve();

    return 0;
}