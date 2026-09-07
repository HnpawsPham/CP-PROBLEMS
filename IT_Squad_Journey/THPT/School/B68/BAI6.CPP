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
#define taskname "BAI6"

int n, m;
const int maxn = 5e4 + 5;
const int oo = 1e9 + 5;
vector<pii> a[maxn];

namespace sub1{
    const int LOG = 16;
    int p[maxn][LOG + 1], h[maxn], dis[maxn];
    int in[maxn], t[maxn], pos[5];
    int cnt = 0;

    bool checksub(){
        for(int i = 1; i <= n; i++)
            if(in[i] > 2) return 0;
        return 1;
    }

    bool comp(int u, int v){
        return t[u] < t[v];
    }

    void dfs(int u){
        t[u] = cnt++;

        for(auto [w, v] : a[u]){
            if(v == p[u][0]) continue;

            h[v] = h[u] + 1;
            dis[v] = dis[u] + w;
            p[v][0] = u;
            dfs(v);
        }
    }

    void prep(){
        h[0] = -1;
        memset(dis, 0, sizeof dis);
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

    void sol(){
        prep();
 
        while(m--){
            for(int i = 0; i < 5; i++){
                cin>>pos[i];
                pos[i]++;
            }
            sort(pos, pos + 5, comp);

            int res = 0;
            for(int i = 0; i < 5; i++)
                res += dis[pos[i]] + dis[pos[(i + 1) % 5]] - 2 * dis[lca(pos[i], pos[(i + 1) % 5])];
            cout<<res / 2<<el;
        }
    }
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
    memset(sub1::in, 0, sizeof sub1::in);

    for(int i = 1; i < n; i++){
        int u, v, w;
        cin>>u>>v>>w;
        u++; v++;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
        sub1::in[u]++;
        sub1::in[v]++;
    }

    cin>>m;
    sub1::sol();
    return 0;
}