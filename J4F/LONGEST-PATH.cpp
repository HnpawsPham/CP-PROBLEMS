#include <bits/stdc++.h>
using namespace std;
#define el "\n"

const int maxn = 2 * (int)1e5 + 5;
int n, m, res = 0;
vector<vector<int>> a(maxn);
vector<int> topo;
int dp[maxn];
bool check[maxn];

void dfs(int u){
    check[u] = 1;
    for(int v : a[u])
        if(!check[v]) dfs(v);
    
    topo.push_back(u);
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    while(m--){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
    }

    memset(dp, 0, sizeof(dp));

    for(int i = 1; i<=n;i++)
        if(!check[i]) dfs(i);

    for(int u : topo){
        for(int v : a[u])
            dp[u] = max(dp[u], dp[v] + 1);
        res = max(res, dp[u]);
    }
    cout<<res;
    return 0;
}