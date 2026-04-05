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

int n;
const int maxn = 1e5 + 5;
const int LOG = 17;
const int oo = 1e6 + 4;
vector<pii> a[maxn];
int p[maxn][LOG + 1], h[maxn], minn[maxn][LOG + 1], maxx[maxn][LOG + 1];

void dfs(int u){
    for(auto [w, v] : a[u]){
        if(v == p[u][0]) continue;
        p[v][0] = u;
        h[v] = h[u] + 1;
        maxx[v][0] = minn[v][0] = w;
        dfs(v);
    }
    return;
}

void prepare(){
    h[1] = 0;
    p[1][0] = 0;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= LOG; j++){
            maxx[i][j] = 0;
            minn[i][j] = oo;
    }
    dfs(1);

    for(int j = 1; j <= LOG; j++)
        for(int i = 1; i <= n; i++){
            p[i][j] = p[p[i][j - 1]][j - 1];
            minn[i][j] = min(minn[i][j - 1], minn[p[i][j - 1]][j - 1]);
            maxx[i][j] = max(maxx[i][j - 1], maxx[p[i][j - 1]][j - 1]);
        }
    return;
}

pii lca(int u, int v){
    int resmin = oo, resmax = 0;

    if(h[u] < h[v]) swap(u, v);

    for(int i = LOG; i >= 0; i--)
        if(h[p[u][i]] >= h[v]){
            resmin = min(minn[u][i], resmin);
            resmax = max(maxx[u][i], resmax);
            u = p[u][i];
        }
    if(u == v) return {resmin, resmax};

    for(int i = LOG; i >= 0; i--)
        if(p[u][i] != p[v][i]){
            resmin = min(resmin, min(minn[u][i], minn[v][i]));
            resmax = max(resmax, max(maxx[u][i], maxx[v][i]));
            u = p[u][i];
            v = p[v][i];
        }

    resmin = min(resmin, min(minn[v][0], minn[u][0]));
    resmax = max(resmax, max(maxx[u][0], maxx[v][0]));
    return {resmin, resmax};
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
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }
    prepare();

    int q;
    cin>>q;
    while(q--){
        int u, v;
        cin>>u>>v;
        pii x = lca(u, v);
        cout<<x.fi<<" "<<x.se<<el;
    }
    return 0;
}