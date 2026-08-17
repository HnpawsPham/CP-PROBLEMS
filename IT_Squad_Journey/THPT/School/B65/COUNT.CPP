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
#define pis pair<int, string> 
#define taskname "COUNT"

int n, k, m;
const int maxn = 1e4 + 5;
const int MOD = 998244353;
char style[maxn];
pis q[maxn];
vi a[maxn];

namespace sub2{
    vll dfs(int u, int parent, const string& s){
        vll sum(m + 1, 0);
        sum[0] = 1;

        for(int v : a[u]){
            if(v == parent) continue;
            vll tmp = dfs(v, u, s);

            for(int i = 0; i <= m; i++)
                sum[i] = (sum[i] + tmp[i]) % MOD;
        }

        vll dp(m + 1, 0);
        dp[0] = sum[0];
        
        for(int i = 1; i <= m; i++){
            dp[i] = sum[i];
            if(style[u] == s[i - 1])
                dp[i] = (dp[i] + sum[i - 1]) % MOD;
        }
        return dp;
    }

    void sol(){
        for(int i = 0; i < k; i++){
            m = q[i].se.length();
            cout<<dfs(q[i].fi, 0, q[i].se).back()<<el;
        }
    }
}

namespace sub3{
    unordered_map<string, ll> mp;
    bool checksub = 1;

    vll dfs(int u, int parent, const string& s){
        vll sum(m + 1, 0);
        sum[0] = 1;

        for(int v : a[u]){
            if(v == parent) continue;
            vll tmp = dfs(v, u, s);

            for(int i = 0; i <= m; i++)
                sum[i] = (sum[i] + tmp[i]) % MOD;
        }

        vll dp(m + 1, 0);
        dp[0] = sum[0];
        
        for(int i = 1; i <= m; i++){
            dp[i] = sum[i];
            if(style[u] == s[i - 1])
                dp[i] = (dp[i] + sum[i - 1]) % MOD;
        }
        return dp;
    }

    void sol(){
        for(int i = 0; i < k; i++){
            if(mp.find(q[i].se) == mp.end()){
                m = q[i].se.length();
                mp[q[i].se] = dfs(q[i].fi, 0, q[i].se).back();
            }
            cout<<mp[q[i].se]<<el;
        }
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

    cin>>n>>k;
    for(int i = 1; i <= n; i++)
        cin>>style[i];

    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    } 

    for(int i = 0; i < k; i++){
        cin>>q[i].fi>>q[i].se;
        if(q[i].fi != 1) 
            sub3::checksub = 0;
    }

    if(sub3::checksub)
        sub3::sol();
    else sub2::sol();
    return 0;
}

// 5 3
// ABBBB
// 2 1
// 3 1
// 4 2
// 5 3
// 1 BA
// 1 BBA
// 2 BB