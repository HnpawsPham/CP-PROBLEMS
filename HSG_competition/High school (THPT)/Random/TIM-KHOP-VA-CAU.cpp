#include <bits/stdc++.h>
using namespace std;
#define el "\n"

const int maxn = 10005;
int n, m, id = 0, brid = 0, ap = 0;
vector<vector<int>> a(maxn);
int idx[maxn], low[maxn];

void dfs(int u, int parent){
    low[u] = idx[u] = ++id;
    int node = (parent != 0);

    for(int v : a[u]){
        if(v == parent) continue;
        
        if(!idx[v]){
            dfs(v, u);
            low[u] = min(low[v], low[u]);
            
            if(low[v] == idx[v]) brid++;
            if(low[v] >= idx[u]) node++;
        }
        else low[u] = min(low[u], idx[v]);
    }
    if(node >= 2) ap++;
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
        a[v].push_back(u);
    }

    memset(idx, 0, sizeof(idx));
    for(int i = 1; i<=n;i++) if(!idx[i]) dfs(i, 0);
    cout<<ap<<" "<<brid;

    return 0;
}