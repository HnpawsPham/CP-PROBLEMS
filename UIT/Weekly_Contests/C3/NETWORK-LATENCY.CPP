#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define vi vector<int>
#define pii pair<ll, int>
#define fi first
#define se second

int n, m, s;
const int maxn = 25005;
const ll oo = LLONG_MAX;
vector<vector<pii>> a(maxn);

void dijkstra(){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<ll> dis(n + 1, oo);
    pq.push({0, s});
    dis[s] = 0;

    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        if(w > dis[u]) continue;

        for(const auto& [w1, v] : a[u]){
            if(dis[v] > dis[u] + w1){
                dis[v] = dis[u] + w1;
                pq.push({dis[v], v});
            }
        }
    }
    for(int i = 1; i <= n; i++)
        cout<<(dis[i] == oo ? -1 : dis[i])<<" ";
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>s;

    int x, y;
    ll z;

    while(m--){
        cin>>x>>y>>z;
        a[x].push_back({z, y});
        a[y].push_back({z, x});
    }
    dijkstra();
    return 0;
}