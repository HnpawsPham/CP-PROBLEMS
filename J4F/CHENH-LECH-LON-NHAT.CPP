#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define piii pair<int, pii>
#define fi first
#define se second
//#define taskname ""

int n, m;
const int maxn = 2e5 + 5;
const int oo = 1e9 + 5;
vector<piii> a[maxn];

vll dijkstra(int st, vi& minn, vi& maxx){
    minn.assign(n + 1, oo);
    maxx.assign(n + 1, 0);
    vll dis(n + 1, 1e16 + 5);

    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dis[st] = 0;
    pq.push({dis[st], st});

    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        if(w > dis[u]) continue;

        for(auto [v, x] : a[u]){
            if(dis[v] > dis[u] + x.se){
                dis[v] = dis[u] + x.se;
                minn[v] = min(minn[u], x.fi);
                maxx[v] = max(maxx[u], x.fi);
                pq.push({dis[v], v});
            }
            else if(dis[v] == dis[u] + x.se){
                int prevmin = minn[v], prevmax = maxx[v];
                minn[v] = min(min(minn[v], minn[u]), x.fi);
                maxx[v] = max(max(maxx[u], maxx[v]), x.fi);

                if(minn[v] != prevmin || maxx[v] != prevmax)
                    pq.push({dis[v], v});
            }
        }
    }
    return dis;
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
        int u, v, w, c;
        cin>>u>>v>>w>>c;
        a[u].push_back({v, {c, w}});
        a[v].push_back({u, {c, w}});
    }

    vi min1n, max1n, minn1, maxn1;
    vll d1n = dijkstra(1, min1n, max1n), dn1 = dijkstra(n, minn1, maxn1);

    int res = 0;
    for(int i = 1; i <= n; i++)
        if(d1n[i] + dn1[i] == d1n[n]){
            res = max(res, maxn1[i] - min1n[i]);
            res = max(res, max1n[i] - minn1[i]);
        }
    cout<<res;
    return 0;
}