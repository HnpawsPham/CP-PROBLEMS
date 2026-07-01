#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define piii pair<int, pii>
#define fi first
#define se second
//#define taskname ""

int n;
const int maxn = 2e5 + 5;
const int LOG = 18;
vector<pii> a[maxn], cost;
int h[maxn], p[maxn][LOG + 1], cnt[maxn] = {0};
ll res = 0;

void prepare(){
    h[0] = -1;
    for(int j = 1; j <= LOG; j++)
        for(int i = 1; i <= n; i++)
            p[i][j] = p[p[i][j - 1]][j - 1];
    return;
}

void dfs(int u, int parent){    
    for(auto& [v, _] : a[u]){
        if(v == parent) continue;
        h[v] = h[u] + 1;
        p[v][0] = u;
        dfs(v, u);
    }    
    return;
}

void across_cnt(int u, int parent, int ed_id){
    for(auto& [v, id] : a[u]){
        if(v == parent) continue;
        across_cnt(v, u, id);
        cnt[u] += cnt[v];
    }

    if(u != 1) res += min(1LL * cnt[u] * 1LL * cost[ed_id].fi, 1LL * cost[ed_id].se);
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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i < n; i++){
        int u, v, w1, w2;
        cin>>u>>v>>w1>>w2;
        cost.push_back({w1, w2});
        a[u].push_back({v, i - 1});
        a[v].push_back({u, i - 1});
    }

    h[0] = -1;
    dfs(1, 0);
    prepare();

    for(int i = 1; i < n; i++){
        int anc = lca(i, i + 1);
        cnt[i]++;
        cnt[i + 1]++;
        cnt[anc] -= 2;
    }

    across_cnt(1, 0, -1);
    cout<<res;
    return 0;
}