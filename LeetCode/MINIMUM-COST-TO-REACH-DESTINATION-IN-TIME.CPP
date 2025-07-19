#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define tii tuple<int, int, int>

const int oo = INT_MAX;
int n, tmax;
vector<vector<pii>> a;

int dijkstra(vi& cost){
    priority_queue<tii, vector<tii>, greater<tii>> pq;
    vector<vi> dp(n, vi(tmax + 1, oo));
    pq.push({cost[0], 0, 0}); // cost, time, node

    while(!pq.empty()){
        auto [w, t, u] = pq.top();
        if(u == n - 1) return w;
        pq.pop();

        for(auto [t1, v] : a[u]){
            if(t + t1 > tmax) continue;

            if(dp[v][t + t1] > w + cost[v]){
                dp[v][t + t1] = w + cost[v];
                pq.push({dp[v][t + t1], t1 + t, v});
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>tmax;

    vector<vi> ed(n);
    for(int i = 0; i < n; i++){
        int u, v, t;
        cin>>u>>v>>t;
        ed[i] = {u, v, t};
    }

    vi cost(n);
    for(int i = 0; i < n; i++) cin>>cost[i];

    a.resize(n);
    for(const vi& v : ed){
        a[v[0]].push_back({v[2], v[1]});
        a[v[1]].push_back({v[2], v[0]});
    }
    cout<<dijkstra(cost);
    return 0;
}

// 6 29
// 0 1 10
// 1 2 10
// 2 5 10
// 0 3 1
// 3 4 10
// 4 5 15
// 5 1 2 20 20 3
