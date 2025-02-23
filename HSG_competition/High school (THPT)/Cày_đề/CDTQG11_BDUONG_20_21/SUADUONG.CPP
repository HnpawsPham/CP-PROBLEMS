#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int, int>
#define fi first
#define se second
#define INF 105

int n, m;
const int maxn = 105;
vector<vector<pii>> a(maxn);
vector<int> dis(maxn, INF);

void dijkstra(){
    priority_queue<pii, vector<pii> , greater<pii>> pq;
    dis[0] = dis[1] = 0;
    pq.push({0, 1});

    while(!pq.empty()){
        pii cur = pq.top();
        pq.pop();

        int u = cur.se;
        int w = cur.fi;

        if(w > dis[u]) continue;
        for(pii x : a[u]){
            int w1 = x.fi;
            int v = x.se;

            if(dis[u] + w1 < dis[v]){
                dis[v] = dis[u] + w1;
                pq.push({dis[v], v});
            }
        }
    }
    return;
}

int main(){
    freopen("SUADUONG.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 0; i< m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
    }
    dijkstra();
    for(int i = 1; i <= n;i++) cout<<dis[i]<<" ";
    return 0;
}