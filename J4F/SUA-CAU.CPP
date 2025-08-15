#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m;
const int maxn = 2e5 + 5;
const int LOG = 20;
vector<vector<pii>> a(maxn);
bitset<maxn> check;
int p[maxn][LOG + 1];
int cnt[maxn] = {0}, h[maxn];

// brute force
// bool dfs(int u, int parent, int t){
//     if(u == t) return 1;

//     for(auto [v, id] : a[u]){
//         if(v == parent) continue;
//         if(dfs(v, u, t)){
//             check[id] = 1;
//             return 1;
//         }
//     }
//     return 0;
// }

void dfs(int u){
    for(auto [v, _] : a[u]){
        if(v == p[u][0]) continue;
        h[v] = h[u] + 1;
        p[v][0] = u;
        dfs(v);
    }
    return;
}

void prepare(){
    h[0] = -1;
    for(int j = 1; j <= LOG; j++)
        for(int i = 1; i <= n; i++)
            p[i][j] = p[p[i][j - 1]][j - 1];
    return;
}

int lca(int u, int v){
    if(h[u] < h[v]) swap(u, v);

    for(int i = LOG; i >= 0; i--)
        if(h[p[u][i]] >= h[v])
            u = p[u][i];

    if(u == v) return u;

    for(int i = LOG; i >= 0; i--)
        if(p[u][i] != p[v][i]){
            u = p[u][i];
            v = p[v][i];
        }
    return p[u][0];
}

void dfs_cnt(int u, int parent){
    for(auto [v, id] : a[u]){
        if(v == parent) continue;
        dfs_cnt(v, u);
        cnt[u] += cnt[v];
        if(cnt[v] > 0) check[id] = 1;
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        a[u].push_back({v, i});
        a[v].push_back({u, i});
    }

    dfs(1);
    prepare();

    cin>>m;
    while(m--){
        int u, v;
        cin>>u>>v;
        cnt[u]++;
        cnt[v]++;
        cnt[lca(u, v)] -= 2;
    }

    dfs_cnt(1, 0);

    int res = n - 1;
    for(int i = 1; i < n; i++)
        res -= check[i];
    cout<<res;
    return 0;
}