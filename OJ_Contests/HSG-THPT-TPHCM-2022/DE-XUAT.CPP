#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int, int>
#define fi first
#define se second

const int oo = INT_MAX;
int n, m, k, s, t, res = oo;
const int maxn = 1e4 + 5;

void dijkstra(vector<pii> a[]){
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
    cout<<(dis[t] != oo ? dis[t] : -1);
    return;
}

// vector<int> dijkstra(int st, vector<pii> a[]){
//     priority_queue<pii, vector<pii>, greater<pii>> pq;
//     pq.push({0, st});
//     vector<int> dis(n + 1, oo);
//     dis[st] = 0;

//     while(!pq.empty()){
//         auto [w, u] = pq.top();
//         pq.pop();

//         if(w > dis[u]) continue;

//         for(auto [w1, v] : a[u]){
//             if(dis[u] != oo && dis[u] + w1 < dis[v]){
//                 dis[v] = dis[u] + w1;
//                 pq.push({dis[v], v});
//             }
//         }
//     }
//     return dis;
// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k>>s>>t;
    vector<pii> a[n + 1];
    // vector<pii> a[n + 1], ra[n + 1];

    // while(m--){
    //     int u, v, w;
    //     cin>>u>>v>>w;
    //     a[u].push_back({w, v});
    //     ra[v].push_back({w, u});
    // }

    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
    }

    while(k--){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }

    dijkstra(a);

    // vector<int> l = dijkstra(s, a), r = dijkstra(t, ra);
    // int res = l[t];

    // while(k--){
    //     int u, v, w;
    //     cin>>u>>v>>w;

    //     if(l[u] != oo && r[v] != oo)
    //         res = min(res, l[u] + w + r[v]);  

    //     if(l[v] != oo && r[u] != oo)
    //         res = min(res, l[v] + w + r[u]);    
    // }
    // cout<<(res != oo ? res : -1);

    return 0;
}