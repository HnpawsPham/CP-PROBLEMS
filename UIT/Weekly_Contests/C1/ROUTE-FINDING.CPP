#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define pii pair<int, int>
#define fi first
#define se second

int n, m, st, en;
const int maxn = 505;
const ll oo = 1e10;
vector<pii> a[maxn];

void dijkstra(){
    vector<ll> dis(n + 1, oo);
    priority_queue<pii> pq;
    int parent[n + 1];

    dis[st] = 0;
    parent[st] = -1;
    pq.push({0, st});

    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        if(w > dis[u]) continue;

        for(const auto& [w1, v] : a[u]){
            if(dis[v] > dis[u] + w1){
                dis[v] = dis[u] + w1;
                parent[v] = u;
                pq.push({dis[v], v});
            }
        }
    }

    if(dis[en] == oo){
        cout<<-1;
        return;
    }

    cout<<dis[en]<<" ";
    
    deque<int> path;
    while(en != -1){
        path.push_front(en);
        en = parent[en];
    }
    for(int x : path) cout<<x<<" ";
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>st>>en;

    while(m--){
        int d, x, y, z;
        cin>>d>>x>>y>>z;
        a[x].push_back({z, y});

        if(d == 2) a[y].push_back({z, x});
    }

    dijkstra();

    return 0;
}