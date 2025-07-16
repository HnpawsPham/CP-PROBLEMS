#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int> 

int n, m;
const int maxn = 1e5 + 5;
vi a[maxn];
vi dp, topo;
int parent[maxn];
bool check[maxn] = {0};

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
    dp.assign(n + 1, 1);

    while(m--){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
    }

    parent[1] = 1;
    dfs(1);

    if(!check[n]) return cout<<"IMPOSSIBLE", 0;

    reverse(topo.begin(), topo.end());
    for(int u : topo)
        for(int v : a[u])
            if(dp[u] + 1 > dp[v]){
                dp[v] = dp[u] + 1;
                parent[v] = u;
            }
    cout<<dp[n]<<el;

    vi res;
    while(n != parent[n]){
        res.push_back(n);
        n = parent[n];
    }
    res.push_back(n);
    reverse(res.begin(), res.end());

    for(int x : res) cout<<x<<" ";
    return 0;
}

// 10 10
// 2 6
// 1 2
// 4 6
// 5 6
// 2 5
// 7 8
// 6 10
// 1 10
// 3 5
// 4 9