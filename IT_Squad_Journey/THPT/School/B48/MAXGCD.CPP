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
#define taskname "MAXGCD"

int a, b;
const ll MOD = 1e9 + 7;

ll ppow(int a, int b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);
    if(b & 1) return half * half % MOD * a % MOD;
    return half* half % MOD;
}

vector<pii> calc(int x){
    vector<pii> res;
    int n = x;
    for(int i = 2; i * i <= n; i++)
        if(x % i == 0){
            int cnt = 0;
            while(x % i == 0){
                x /= i;
                cnt++;
            }
            res.push_back({i, cnt});
        }
    if(x > 1) res.push_back({x, 1});
    return res;
}

ll fact(int x){
    if(x <= 1) return 1;
    return x * fact(x - 1) % MOD;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>a>>b;

    vector<pii> diva = calc(a), divb = calc(b);

    ll res = fact(min(a, b));
    // for(pii x : diva)
    //     for(pii y : divb)
    //         if(x.fi == y.fi){
    //             res = res * ppow(x.fi, min(x.se, y.se)) % MOD;
    //             cout<<x.fi<<" ";
    //         }

    cout<<res;
    return 0;
}