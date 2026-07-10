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
#define taskname "CAU6"

int n;
const int maxn = 2e5 + 5;
const int MOD = 1e9 + 7;
vi a[maxn];

namespace sub1{
    int in[maxn] = {0}, pos[maxn] = {0};

    bool check(){
        for(int i = 1; i <= n; i++)
            if(in[i] > 2) return 0;
        return 1;
    }

    void dfs(int u, int p, int d){
        pos[u] = d;
        for(int v : a[u]){
            if(v == p) continue;
            dfs(v, u, d + 1);
        }
    }

    void sol(){
        for(int i = 1; i <= n; i++)
            if(in[i] == 1){
                dfs(i, 0, 1);
                break;
            }

        for(int i = 1; i <= n; i++)
            cout<<pos[i] * (n - pos[i] + 1) % MOD<<" ";
    }
};

namespace sub2{
    ll ppow(ll a, int b){
        if(b == 0) return 1;
        ll half = ppow(a, b / 2);
        if(b & 1) return half * half % MOD * a % MOD;
        return half * half % MOD;
    }

    void sol(){
        cout<<ppow(2, n - 1)<<" ";
        for(int i = 2; i <= n; i++)
            cout<<(ppow(2, n - 2) + 1) % MOD<<" ";
    }
};

namespace sub3{
    ll dp[maxn];

    void dfs(int u, int p){
        dp[u] = 1;
        for(int v : a[u]){
            if(v == p) continue;
            dfs(v, u);
            dp[u] = (dp[u] * (1 + dp[v]) % MOD) % MOD;
        }
    }

    void sol(){
        for(int i = 1; i <= n; i++){
            dfs(i, 0);
            cout<<dp[i]<<" ";
        }
    }
};

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    bool checksub1 = 1, checksub2 = 1;
    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;

        sub1::in[u]++;
        sub1::in[v]++;

        if(u != 1 && v != 1) 
            checksub2 = 0;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    if(sub1::check()) sub1::sol();
    else if(checksub2) sub2::sol();
    else sub3::sol();
    return 0;
}