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
const int maxn = 1e5 + 5;
const int LOG = 17;
vector<piii> a[maxn];
int p[maxn][LOG + 1], h[maxn], pass[maxn];

void dfs(int u){
    for(auto [v, _] : a[u]){
        if(v == p[u][0]) continue;
        h[v] = h[u] + 1;
        p[v][0] = u;
        dfs(v);
    }
}

void prep(){
    memset(pass, 0, sizeof pass);
    h[0] = -1;
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

ll res = 0;
void calc(int u, int w1, int w2){
    for(auto [v, cost] : a[u]){
        if(v == p[u][0]) continue;
        calc(v, cost.fi, cost.se);
        pass[u] += pass[v];
    }
    res += min(1LL * pass[u] * w1, 1LL * w2);
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
        a[u].push_back({v, {w1, w2}});
        a[v].push_back({u, {w1, w2}});
    }

    prep();
    for(int i = 2; i <= n; i++){
        pass[i]++;
        pass[i - 1]++;
        pass[lca(i, i - 1)] -= 2;
    }
    calc(1, 0, 0);
    cout<<res;
    return 0;
}