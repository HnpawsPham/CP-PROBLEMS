#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int, int>

int n, mdb, mds, st, en;
const int maxn = 3 * (int)1e4 + 5;

vector<vector<pii>> db, ds;

int dijkstra(int x, int t, vector<vector<pii>> a){
    priority_queue<pii> pq;
    vector<int> dis(n, INT_MAX);
    dis[x] = 0;
    pq.push({dis[x], x});

    while(!pq.empty()){
        pii cur = pq.top(); pq.pop();

        int u = cur.second;
        int w = cur.first;

        if(w > dis[u]) continue;

        for(pii d : a[u]){
            int v = d.second;
            int w1 = d.first;

            if(dis[u] != INT_MAX && dis[u] + w1 < dis[v]){
                dis[v] = dis[u] + w1;
                pq.push({dis[v], v});
            }
        }
    }
    return dis[t];
}

int main(){
    freopen(".\\txt\\SHORTEST.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>mdb>>mds;
    for(int i = 0;i< mdb; i++){
        int u, v, w;
        cin>>u>>v>>w;
        db[u].push_back({v, w});
    }
    for(int i = 0;i<mds; i++){
        int u, v, w;
        cin>>u>>v>>w;
        ds[u].push_back({v, w});
    }
    cin>>st>>en;


    return 0;
}