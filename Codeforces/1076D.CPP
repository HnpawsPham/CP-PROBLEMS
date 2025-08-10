#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define pli pair<ll, int>
#define tiii tuple<int, int, int>

int n, m, k, cnt = 0;
const int maxn = 3e5 + 5;
const ll oo = LLONG_MAX;
vector<vector<tiii>> a(maxn);
vi res;

void dijkstra(int st){
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    vector<ll> dis(n + 1, oo);
    int parentId[n + 1] = {0};
    dis[st] = 0;
    pq.push({dis[st], st});

    while(!pq.empty() && cnt < k){
        auto [w, u] = pq.top();
        pq.pop();

        if(1LL * w > dis[u]) continue;

        if(parentId[u]){
            res.push_back(parentId[u]);
            cnt++;
        }
 
        for(auto [w1, v, id] : a[u]){
            if(dis[v] > dis[u] + w1){
                dis[v] = 1LL * dis[u] + w1;
                parentId[v] = id;
                pq.push({dis[v], v});
            }
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v, i});
        a[v].push_back({w, u, i});
    }

    dijkstra(1);
    
    cout<<res.size()<<el;
    for(int x : res) cout<<x<<" ";
    return 0;
}