#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>

int n;
const int maxn = 2e5 + 5;
const int LOG = 19;
const ll oo = 1e15;
vi a[maxn];
int p[maxn][LOG + 1], h[maxn], cnt[maxn] = {0};

void dfs(int u){
    for(int v : a[u]){
        if(v == p[u][0]) continue;
        p[v][0] = u;
        h[v] = h[u] + 1;
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

void dfs2(int u){
    for(int v : a[u]){
        if(v == p[u][0]) continue;
        dfs2(v);
        cnt[u] += cnt[v];
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vector<vi> ed;
    for(int i = 1; i < n; i++){
        int u, v, c1, c2;
        cin>>u>>v>>c1>>c2;
        a[u].push_back(v);
        a[v].push_back(u);
        ed.push_back({u, v, c1, c2});
    }

    p[1][0] = 0;
    dfs(1);
    prepare();

    for(int u = 1; u < n; u++){
        int v = u + 1;
        cnt[u]++;
        cnt[v]++;
        cnt[lca(u, v)] -= 2;
    }
    dfs2(1);

    ll res = 0;
    for(const auto& e : ed){
        int u = e[0], v = e[1], c1 = e[2], c2 = e[3];
        if(u == p[v][0]) res += min(1LL * cnt[v] * c1, 1LL * c2);
        else res += min(1LL * cnt[u] * c1, 1LL * c2);
    }
    cout<<res;
    return 0;
}