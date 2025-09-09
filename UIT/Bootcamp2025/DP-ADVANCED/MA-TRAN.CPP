#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m, a, b;
const ll MOD = 998244353;

ll ppow(int a, int b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);
    if(b & 1) return half * half % MOD * a % MOD;
    return half * half % MOD;
}

ll C2(int n){
    return 1LL * (n + 1) % MOD * n % MOD * ((MOD + 1) / 2) % MOD;
}

ll sol(){
    // th1
    ll res = 0;
    res += (a + 1) * (b + 1);
    // th2,3
    res = (res + 1LL * (a + 1) * C2(b) % MOD * (ppow(2, m) - 2) % MOD) % MOD;
    res = (res + 1LL * (b + 1) * C2(a) % MOD * (ppow(2, n) - 2) % MOD) % MOD;
    // th4


    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin>>tc;
    while(tc--){
        cin>>n>>m>>a>>b;
        cout<<sol()<<el;
    }

    return 0;
}