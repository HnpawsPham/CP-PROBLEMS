#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m, cntpath = 0;
const int oo = 1e7;
const int maxn = 30005;
vector<vector<pii>> a(maxn);

pair<vi, vector<ll>> dijkstra(int st){
    vi dis(n + 1, oo);
    vector<ll> cnt(n + 1, 0);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, st});
    dis[st] = 0;
    cnt[st] = 1;
    
    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        if(w > dis[u]) continue;

        for(auto [w1, v] : a[u]){
            if(dis[v] > dis[u] + w1){
                dis[v] = dis[u] + w1;
                cnt[v] = cnt[u];
                pq.push({dis[v], v});
            }
            else if(dis[v] == dis[u] + w1)
                cnt[v] += cnt[u];
        }
    }
    return {dis, cnt};
}

int main(){
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

    auto [dis1, cnt1] = dijkstra(1);
    auto [disn, cntn] = dijkstra(n);
   
    vi res;

    for(int u = 2; u < n; u++){
        if(dis1[u] + disn[u] != dis1[n] || 1LL * cnt1[u] * cntn[u] != cnt1[n])
            res.push_back(u);
    }
    cout<<res.size()<<el;
    for(int x : res) cout<<x<<el;
    return 0;
}