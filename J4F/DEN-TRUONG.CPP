#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""

int n, m;
const int maxn = 5005;
const int oo = 2e8 + 5;
vector<pii> a[maxn];

void dijkstra(){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vi dis(n + 1, oo);
    vll cnt(n + 1, 0);
    dis[1] = 0;
    cnt[1] = 1;
    pq.push({dis[1], 1});

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
    
    cout<<dis[n]<<" "<<cnt[n];
    return;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    while(m--){
        int opt, u, v, w;
        cin>>opt>>u>>v>>w;
        a[u].push_back({w, v});

        if(opt == 2)
            a[v].push_back({w, u});
    }
    dijkstra();
    return 0;
}