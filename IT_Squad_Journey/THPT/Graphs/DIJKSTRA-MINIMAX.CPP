#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define pii pair<ll, int>

int n, m;
const int maxn = 2e5 + 5;
const ll oo = 1e15;
vector<vector<pii>> a(maxn);

void dijkstra(){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<ll> dis(n + 1, oo);
    bool check[n + 1] = {0};
    pq.push({0, 1});

    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        if(check[u]) continue;
        dis[u] = w;
        check[u] = 1;

        for(auto [w1, v] : a[u])
            if(!check[v])
                pq.push({max(w1, w), v});
    }

    for(int i = 1; i <= n; i++) 
        cout<<dis[i]<<" ";
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    while(m--){
        int u, v;
        ll w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }
    dijkstra();

    return 0;
}