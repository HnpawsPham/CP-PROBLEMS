#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int, int>
#define piii pair<ll, pii>
#define fi first
#define se second
#pragma GCC ("O2,Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

int n, m, d;
const int maxn = 2e5 + 2;
vector<pii> a[maxn];

ll dijkstra(){
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    pq.push({0, {1, -1}});
    unordered_map<int, ll> dis[n + 1];
    dis[1][-1] = 0;

    while(!pq.empty()){
        auto [w, cur] = pq.top();
        auto [u, l] = cur;
        pq.pop();

        if(w > dis[u][l]) continue;
        if(u == n) return w;

        for(auto [l1, v] : a[u]){
            if(l != -1 && l + d > l1) continue;
            if(!dis[v].count(l1) || w + l1 < dis[v][l1]){
                dis[v][l1] = w + l1;
                pq.push({w + l1, {v, l1}});
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>d;
    int u, v, w;
    while(m--){
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }
    cout<<dijkstra();
    return 0;
}