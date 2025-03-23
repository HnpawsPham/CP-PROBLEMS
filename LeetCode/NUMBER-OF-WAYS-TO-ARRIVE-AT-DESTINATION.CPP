#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int, int>
#define fi first
#define se second
#define MOD 1000000007

int n, m;
const int maxn = 1e5;
vector<pii> a[maxn];

void dijkstra(int x){
    vector<int> dis(n, INT_MAX), dp(n, 0);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, x});
    dis[x] = 0;
    dp[x] = 1;

    while(!pq.empty()){
        pii cur = pq.top();
        pq.pop();

        int u = cur.se;
        int w = cur.fi;

        if(w > dis[u]) continue;

        for(pii x : a[u]){
            int v = x.se;
            int w1 = x.fi;

            if(dis[v] > dis[u] + w1){
                dis[v] = dis[u] + w1;
                dp[v] = dp[u];
                pq.push({dis[v], v});
            }
            else if(dis[v] == dis[u] + w1)
                dp[v] = (dp[v] + dp[u]) % MOD;
        }
    }
    cout<<dp[n - 1];
    return;
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

    dijkstra(0);
    return 0;
}