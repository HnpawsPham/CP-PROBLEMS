#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define pii pair<ll, int>
#define fi first
#define se second

int t, n, m;
const ll oo = 1e15;
vector<vector<pii>> a;

vector<ll> dijkstra(int st){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<ll> dis(n + 1, oo);
    bool check[n + 1] = {0};

    pq.push({0, st});

    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        if(check[u]) continue;
        dis[u] = w;
        check[u] = 1;

        for(auto [w1, v] : a[u])
            if(!check[v])
                pq.push({max(w, w1), v});
    }
    return dis;
}

void sol(){
    vector<ll> l = dijkstra(1), r = dijkstra(n);

    ll res = oo;
    for(int u = 1; u <= n; u++)
        for(auto [w, v] : a[u])
            res = min(res, max({l[u], r[v], w}) + w);
        
    cout<<res<<el;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n>>m;
        a.clear();
        a.resize(n + 1);

        while(m--){
            int u, v;
            ll w;
            cin>>u>>v>>w;

            a[u].push_back({w, v});
            a[v].push_back({w, u});
        }
        sol();
    }

    return 0;
}