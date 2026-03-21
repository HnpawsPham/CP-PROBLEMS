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
#define taskname "ROBOTS"

int n, m, x, y, id = 0;
const int maxn = 1e5 + 5;
const ll oo = 1e16 + 5;

vector<pii> a[maxn], bridge;
int low[maxn], idx[maxn] = {0};

void tarjan(int u, int p){
    idx[u] = low[u] = ++id;

    for(auto [_, v] : a[u]){
        if(!idx[v]){
            tarjan(v, u);
            low[u] = min(low[u], low[v]);

            if(low[v] > idx[u])
                bridge.push_back({u, v});
        }
        else if(v != p)
            low[u] = min(low[u], idx[v]);
    }
    return;
}

vll dijkstra(int st){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vll dis(n + 1, oo);
    dis[st] = 0;
    pq.push({0, st});

    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        if(w > dis[u]) continue;

        for(auto [w1, v] : a[u]){
            if(dis[v] > dis[u] + w1){
                dis[v] = dis[u] + w1;
                pq.push({dis[v], v});
            }
        }
    }
    return dis;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }
    cin>>x>>y;

    tarjan(1, 0);
    vll dis1 = dijkstra(x), dis2 = dijkstra(y);
    
    ll res = oo;
    for(auto [u, v] : bridge){
        ll tmp1 = max(dis1[u], dis2[v]);
        ll tmp2 = max(dis1[v], dis2[u]);
        res = min(res, min(tmp1, tmp2));
    }
    cout<<res;
    return 0;
}

// 8 11
// 1 2 3
// 1 3 5
// 1 4 8
// 2 4 3
// 3 4 4
// 4 5 2
// 5 6 9
// 5 7 3
// 6 7 4
// 6 8 5
// 7 8 6
// 3 6