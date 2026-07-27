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
#define taskname "CONGTY"

int n, q;
const int maxn = 2e5 + 5;
vi a[maxn];
int w[maxn], p[maxn];

namespace sub2{
    int sz[maxn];

    bool check(int u){
        for(int u = 1; u <= n; u++)
            for(int v : a[u])
                if(w[v] >= w[u]) return 0;
        return 1;
    }

    void sol(){
        for(int i = 1; i <= n; i++)
            sz[i] = 1;
        
        for(int i = n; i > 1; i--)
            sz[p[i]] += sz[i];

        while(q--){
            int x;
            cin>>x;
            cout<<sz[x]<<el;
        }
    }
}

namespace sub3{
    bool checksub = 1;

    void sol(){
        int res[n + 1];
        memset(res, 0, sizeof res);

        vi dp;
        for(int i = n; i > 0; i--){
            auto it = lower_bound(dp.begin(), dp.end(), w[i]);

            if(it == dp.end())
                dp.push_back(*it);
            else *it = w[i];

            res[i] = dp.size();
        }

        while(q--){
            int x;
            cin>>x;
            cout<<res[x]<<el;
        }
    }
}

namespace sub4{
    const int maxa = 105;
    ll dp[maxn][maxa];

    void dfs(int u){
        for(int v : a[u])
            dfs(v);    

        for(int x = 0; x < maxa; x++){
            int sumu = 0, sumnu = 0;
            
            for(int v : a[u])
                sumnu += dp[v][x];
            
            if(w[u] <= x){
                sumu++;
                for(int v : a[u])
                    sumu += dp[v][w[u] - 1];
            }
            dp[u][x] = max(sumu, sumnu);
        }

        for(int i = 1; i < maxa; i++)
            dp[u][i] = max(dp[u][i], dp[u][i - 1]);
    }

    void sol(){
        memset(dp, 0, sizeof dp);
        dfs(1);

        while(q--){
            int u;
            cin>>u;
            cout<<dp[u][maxa - 1]<<el;
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

    cin>>n>>q;
    memset(w, 0, sizeof w);
    for(int i = 1; i <= n; i++) cin>>w[i];
    for(int i = 2; i <= n ;i++){
        cin>>p[i];
        if(p[i] != i - 1) sub3::checksub = 0;
        a[p[i]].push_back(i);
    }

    if(sub2::check(1))
        sub2::sol();
    else if(sub3::checksub)
        sub3::sol();
    else sub4::sol();
    return 0;
}