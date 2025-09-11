#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, t;
const int maxn = 505;
vi a[maxn];
int parent[maxn] = {-1}, dis[maxn] = {0};
bitset<maxn> check;
vi sz(maxn, 1);

void dfs(int u){
    check[u] = 1;
    
    for(int v : a[u]){
        if(check[v]) continue;
        parent[v] = u;
        dis[v] = dis[u] + 1;
        dfs(v);
        sz[u] += sz[v];
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>t;
    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    parent[1] = 1;
    dis[1] = 0;
    dfs(1);

    if(t == 1)
        for(int i = 1; i <= n; i++) cout<<parent[i]<<" ";
    else if(t == 2)
        for(int i = 1; i <= n; i++) cout<<dis[i]<<" ";
    else if(t == 3){
        for(int i = 1; i <= n; i++) 
            if(a[i].size() == 1) cout<<i<<" ";
    }
    else for(int i = 1; i <= n; i++) cout<<sz[i]<<" ";
    return 0;
}