#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define taskname "BAI3"

int n, m, cost;
const int maxn = 1e5 + 5;
const ll oo = 1e16 + 5;
int cntstu[maxn];
vector<pii> a[maxn];

vll dijkstra(){
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vll dis(n + 1, oo); 
    dis[1] = 0;
    pq.push({0, 1});

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

namespace sub2{
    void sol(){
        vll dis1 = dijkstra();

        int parent[n + 1];
        memset(parent, 0, sizeof parent);

        for(int u = 1; u <= n; u++)
            for(const auto&[w, v] : a[u]){
                if(dis1[v] + w != dis1[u]) continue;
                if(!parent[v] || u < parent[v])
                    parent[v] = u;
            }
                   
                    
        int cnt[n + 1];
        for(int i = 1; i <= n; i++){
            cnt[i] = 0;
            int u = i;
            while(u){
                cnt[i] += cntstu[u];
                u = parent[u];
            }
        }

        ll res = 0;
        for(int x = 1; x <= n; x++)
            res = max(res, cnt[x] * (dis1[x] - cost));
        cout<<res;
    }
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>cost;
    for(int i = 1; i <= n; i++) cin>>cntstu[i];

    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }

    // if(n <= 1000)
        sub2::sol();
    return 0;
}