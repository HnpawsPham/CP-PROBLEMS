#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m, k;
const int maxn = 1005;
const int oo = 1e9;
vector<pii> a[maxn];

vi dijkstra(int st){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vi dis(n + 1, oo);
    dis[st] = 0;
    pq.push({0, st});

    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        if(w > dis[u]) continue;

        for(auto [w1, v] : a[u]){
            if(dis[u] + w1 < dis[v]){
                dis[v] = dis[u] + w1;
                pq.push({dis[v], v});
            }
        }
    }
    return dis;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }

    pii q[k];
    for(int i = 0; i < k; i++){
        int u, v;
        cin>>u>>v;
        q[i] = {u, v};
    }

    vi d[n + 1];
    for(int u = 1; u <= n; u++)
        d[u] = dijkstra(u);

    int res = oo;
    for(int u = 1; u <= n; u++)
        for(auto [w, v] : a[u]){
            int tmp = 0;
            for(auto [s, t] : q)
                tmp += min({d[s][t], d[s][v] + d[u][t], d[s][u] + d[v][t]});

            res = min(res, tmp);
        }
    cout<<res;
    return 0;
}