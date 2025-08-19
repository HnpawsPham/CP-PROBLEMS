#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second
#define vll vector<ll>

const int MOD = 1e9 + 7;

ll ppow(int a, int b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);
    if(b & 1) return 1LL * half * half % MOD * a % MOD;
    return 1LL * half * half % MOD;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    vi a(n);
    vector<vi> que(m, vi(4));
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>que[i][0]>>que[i][1]>>que[i][2]>>que[i][3];

    int sz = sqrt(n);
    vll b(n, 1);
    vector<vector<vi>> sq; //small k queries

    for(const auto& q : que){
        int l = q[0], r = q[1], k = q[2], v = q[3];

        if(k > sz){
            for(int i = l; i <= r; i+=k) 
                b[i] = b[i] * v % MOD;
        }
        else sq[k].push_back({l, r, v});
    }

    for(int k = 0; k <= sz; k++){
        if(sq[k].empty()) continue;
        vector<vll> d(k, vll((n + k - 1) / k + 2, 1));

        for(const auto& q : sq[k]){
            int l = q[0], r = q[1], v = q[2];
            int mod = l % k;

            int st = (l - mod) / k;
            int en = (r - mod) / k;

            d[mod][st] = d[mod][st] * v % MOD;
            d[mod][en + 1] = d[mod][en * 1] * ppow(v, MOD - 2) % MOD;
        }
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        a[i] = 1LL * a[i] * b[i] % MOD;
        res ^= a[i];
    }
    cout<<res;
    return 0;
}