#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
const int maxn= 2030;
int h[maxn], dp[maxn][2];
vector<vector<int>> a(maxn);

void dfs(int u, int parent){
    dp[u][1] = h[u];
    dp[u][0] = 0;

    for(int v : a[u]){
        if(v == parent) continue;
        dfs(v, u);

        dp[u][1] += dp[v][0];
        dp[u][0] += max(dp[v][1], dp[v][0]);
    }
    return;
}

int main(){
    freopen(".\\txt\\BUA-TIEC.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i <= n; i++) cin>>h[i];
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;

        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1, 0);
    cout<<max(dp[1][0], dp[1][1]);

    return 0;
}