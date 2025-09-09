#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define tiii tuple<ll, ll, int>
#define fi first
#define se second

int n, m;
const int maxn = 5005;
const ll oo = LLONG_MAX;
vi a[maxn];
int w[maxn];
ll res = 0;

void dijkstra(){
    priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
    vector<ll> dis(n + 1, oo);
    dis[1] = 0;
    pq.push({0, w[1], 1});

    while(!pq.empty()){
        auto [fuel, curw, u] = pq.top();
        pq.pop();

        if(fuel > dis[u]) continue;

        for(int v : a[u]){
            if(fuel + curw < dis[v]){
                dis[v] = fuel + curw;
                pq.push({dis[v], curw + w[v], v});
            }
        }
    }

    for(int i = 1; i <= n; i++) cout<<dis[i]<<el;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 1; i <= n; i++) cin>>w[i];

    while(m--){
        int u, v;
        cin>>u>>v;
        if(u == v) continue;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dijkstra();
    return 0;
}