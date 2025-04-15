#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int, int>
#define fi first
#define se second

int tcase, n, m, q, s, t;
const int maxn = 10005;
const int oo = INT_MAX;
vector<pii> a[maxn], ra[maxn];
int dis[2][maxn];

void dijkstra(int src, vector<pii> g[], int d[]){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i = 1; i <= n; ++i) d[i] = oo;
    d[src] = 0;
    pq.push({0, src});

    while(!pq.empty()){
        auto [du, u] = pq.top(); pq.pop();

        if(du > d[u]) continue;
        
        for(auto [w, v] : g[u]){
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
    return;
}

void init(){
    cin >> n >> m >> q >> s >> t;
    for(int i = 1; i <= n; ++i){
        a[i].clear();
        ra[i].clear();
    }

    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({w, v});
        ra[v].push_back({w, u});
    }
    return;
}

void sol(){
    dijkstra(s, a, dis[0]);
    dijkstra(t, ra, dis[1]);

    int res = dis[0][t];

    while(q--){
        int u, v, w;
        cin >> u >> v >> w;
        if(dis[0][u] != oo && dis[1][v] != oo)
            res = min(res, dis[0][u] + w + dis[1][v]);
        if(dis[0][v] != oo && dis[1][u] != oo)
            res = min(res, dis[0][v] + w + dis[1][u]);
    }

    cout << (res < oo ? res : -1) << el;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tcase;
    while(tcase--){
        init();
        sol();
    }
    return 0;
}
