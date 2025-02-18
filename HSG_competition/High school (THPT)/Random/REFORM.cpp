#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

const int maxn = 2 * (int)1e5;
int n, m, id = 0, scc = 0, b = 0;
ll con = 0;
vector<vector<int>> a(maxn);
int idx[maxn], low[maxn], node[2], dp[maxn]; 

void dfs(int u, int parent){
    idx[u] = low[u] = ++id;
    node[scc - 1]++;

    for(int v : a[u]){
        if(!idx[v]){
            dfs(v, u);
            dp[u] += dp[v];

            low[u] = min(low[u], low[v]);
            if(low[v] == idx[v]){
                b++;
                con += 1LL * dp[v] * (n - dp[v]) - 1;
            } 
        }
        else if(v != parent) low[u] = min(low[u], idx[v]);
    }
    dp[u]++;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 0; i<m; ++i){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    memset(idx, 0, sizeof(idx));
    memset(dp, 0, sizeof(dp));
    node[0] = node[1] = 0;

    for(int i = 1; i<=n; ++i) 
        if(!idx[i]){
            scc++;
            if(scc > 2) return cout<<0, 0;
            dfs(i, 0);
        }
    if(scc == 1) cout<<1LL * con + (1LL * n*(n - 1)/2 - m) * 1LL * (m - b);
    else cout<<1LL * (m - b) * 1LL * node[0] * node[1];
    return 0;
}