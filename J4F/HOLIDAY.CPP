#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""
#pragma GCC optimize("O2,unroll-loops,no-stack-protector")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

int n, q;
const int maxn = 1e6 + 2;
const int LOG = 19;
vector<pii> a[maxn];
int p[maxn][LOG + 1], h[maxn], city[maxn];
ll dis[maxn];

void dfs(int u){
    for(const auto& [w, v] : a[u]){
        if(v == p[u][0])continue;
        p[v][0] = u;
        h[v] = h[u] + 1;
        dis[v] = dis[u] + w + 1;
        dfs(v);
    }
}

void prep(){
    h[0] = -1;
    dis[1] = 0;
    dfs(1);

    for(int j = 1; j <= LOG; j++)
        for(int i = 1; i <= n; i++)
            p[i][j] = p[p[i][j - 1]][j - 1];
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

ll getdis(int u, int v){
    return dis[u] + dis[v] - 2 * dis[lca(u, v)];
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    for(int i= 1; i < n; i++){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }

    prep();
    while(q--){
        int m;
        cin>>m;
        for(int i = 0; i < m; i++) cin>>city[i];

        int st = city[0];
        ll maxx = 0;
        for(int i = 1; i < m; i++){
            ll tmp = getdis(city[0], city[i]);
            if(maxx < tmp){
                st = city[i];
                maxx = tmp;
            }
        }

        for(int i = 0; i < m; i++){
            if(city[i] == st) continue;
            ll tmp = getdis(st, city[i]);

            if(maxx < tmp) maxx = tmp;
        }        
        cout<<maxx<<el;
    }
    return 0;
}