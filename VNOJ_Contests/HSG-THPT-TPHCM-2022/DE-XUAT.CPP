#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int, int>
#define fi first
#define se second

const int oo = INT_MAX;
int n, m, k, s, t, res = oo;
const int maxn = 1e4 + 5;
vector<pii> a[maxn];

void dijkstra(){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    vector<int> dis(n + 1, oo);
    dis[s] = 0;

    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        if(w > dis[u]) continue;

        for(auto [w1, v] : a[u]){
            if(dis[u] != oo && dis[u] + w1 < dis[v]){
                dis[v] = dis[u] + w1;
                pq.push({dis[v], v});
            }
        }
    }
    cout<<(dis[t] != oo ? dis[t] : -1)<<el;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k>>s>>t;
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
    }

    while(k--){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
    }

    dijkstra();

    return 0;
}