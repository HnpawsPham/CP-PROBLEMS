#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int, int>
#define fi first
#define se second

int n, m, id = 1, cnt;
const int maxn = 1e5 + 5;
vector<vector<int>> a(maxn);
int bcc[maxn] = {};
int low[maxn], idx[maxn];
bool check[maxn];
set<pii> bridge;

void dfs(int u, int parent){
    low[u] = idx[u] = ++id;
    check[u] = 1;

    for(int v : a[u]){
        if(v == parent) continue;
        if(!check[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            if(low[v] == idx[v]) 
                bridge.insert({max(u, v), min(u, v)});
        }
        else low[u] = min(low[u], idx[v]);
    }
    return;
}

void init_bcc(int u, int id){
    check[u] = 1;
    bcc[id]++;

    for(int v : a[u])
        if(!check[v] && bridge.find({max(u, v), min(u, v)}) == bridge.end())
            init_bcc(v, id);
    return;
}

int main(){
    freopen("XAY-DUNG-DOANH-TRAI.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) 
        if(!check[i]) dfs(i, 0);
    
    memset(check, 0, sizeof(check));
    int bcc_id = 0;
    for(int i = 1; i <= n; i++)
        if(!check[i]) 
            init_bcc(i, bcc_id++);
    
    int res = 0;
    for(int sz : bcc){
        res += sz * (sz - 1) / 2;
    }
    cout<<res;
    return 0;
}