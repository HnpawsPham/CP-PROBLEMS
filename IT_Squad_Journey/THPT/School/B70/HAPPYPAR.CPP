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
#define taskname "HAPPYPAR"

int n, m;
ll total;
const int maxn = 2e5 +5;
const int MOD = 998244353;
int a[maxn];

ll ppow(int a, int b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);
    if(b & 1) return half * half % MOD * a % MOD;
    return half * half % MOD;
}

namespace sub2{
    void sol(){
        unordered_set<int> check;

        ll res = 0;
        for(int l = 0; l < n; l++){
            ll sum = 0;
            for(int r = l; r < n; r++){
                if(check.find(a[r]) == check.end()){
                    sum = (sum + a[r]) % MOD;
                    check.insert(a[r]);
                }
                res = (res + (total - sum + MOD) % MOD) % MOD;
            }
            check.clear();
        }
        cout<<res;
    }
}

namespace sub3{
    void sol(){
        unordered_map<int, int> last;
        ll res = 1LL * n * 1LL * ((n + 1) % MOD) % MOD * ppow(2, MOD - 2) % MOD;
        res = res * total % MOD;

        for(int l = 0; l < n; l++){
            int prev = (last.find(a[l]) == last.end() ? -1 : last[a[l]]);
            ll cnt = 1LL * a[l] * 1LL * (l - prev) % MOD * 1LL * (n - l) % MOD;
            res = (res - cnt + MOD) % MOD;
            last[a[l]] = l;
        }
        cout<<res;
    }
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 0; i < n; i++) cin>>a[i];
    total = (1LL * m * 1LL * ((m + 1) % MOD) % MOD) * ppow(2, MOD - 2) % MOD;

    if(n <= 2000 && m <= 2000)
        sub2::sol();
    else sub3::sol();
    // sub3::sol();
    return 0;
}