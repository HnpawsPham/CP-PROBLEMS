#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int, int>
#define fi first
#define se second

int tcase, n, m, q, s, t;
const int maxn = 10005;
const int oo = INT_MAX;
vector<pii> a[maxn], ra[maxn], b[maxn];
int dis[3][maxn];

void dijkstra(int s, vector<pii> g[], int dis[]){
    dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});

    while(!pq.empty()){
        int w = pq.top().fi;
        int u = pq.top().se;
        pq.pop();

        if(w > dis[u]) continue;

        for(pii x : g[u]){
            int v = x.se;
            int w1 = x.fi;

            if(dis[v] > dis[u] + w1){
                dis[v] = dis[u] + w1;
                pq.push({dis[v], v});
            }
        }
    }
    return;
}

void init(){
    cin>>n>>m>>q>>s>>t;
    for(int i = 1; i <= n; i++){
        a[i].clear();
        ra[i].clear();
        b[i].clear();
    }

    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        ra[v].push_back({w, u});
    }

    while(q--){
        int u, v, w;
        cin>>u>>v>>w;
        b[u].push_back({w, v});
        b[v].push_back({w, u});
    }
    return;
}

void sol(){
    memset(dis, 0x3f, sizeof(dis));
    dijkstra(s, a, dis[0]);
    dijkstra(t, ra, dis[1]);

    int res = dis[0][t];
    
    for(int i = 1; i <= n; i++)
        for(pii x : b[i])
            res = min(res, dis[0][i] + x.fi + dis[1][x.se]);
    
    cout<<(res < oo ? res : -1);
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tcase;
    while(tcase--){
        init();
        sol();
    }

    return 0;
}