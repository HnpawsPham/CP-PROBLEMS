#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define fi first
#define se second
//#define taskname ""

const int maxn = 5e4 + 5;
const ll oo = 1e15 + 5;
vector<pii> a[maxn];

bool dijkstra(int t, ll k){
    priority_queue<pli> pq;
    vll dis(n, oo);
    pq.push({dis[0], 0});

    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        if(w > k) return 0;
        if(u == n - 1) return 1;
        if(w > dis[u]) continue;

        for(auto& [w1, v] : a[u]){
            if(w1 < t) continue;
            if(dis[v] > dis[u] + w1){
                dis[v] = dis[u] + w1;
                pq.push({dis[v], v});
            }
        }
    }
    return 0;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin>>n>>m>>k;
    
    bool online[n];
    for(int i = 0; i < n; i++) cin>>online[i];

    vector<vi> ed(m, vi(3));
    for(int i = 0; i < m; i++)
        cin>>ed[i][0]>>ed[i][1]>>ed[i][2];

    for(const vi& v : ed)
        if(online[v[0]] && online[v[1]])
            a[v[0]].push_back({v[2], v[1]});
 
    int l = 0, r = 1e9 + 5, mid;
    while(l <= r){
        mid = (l + r) / 2;
        if(dijkstra(t, k))
            l = mid + 1;
        else r = mid - 1;
    }
    cout<<r;
    return 0;
}

// 4 4 10
// 1 1 1 1
// 0 1 5
// 1 3 10
// 0 2 3
// 2 3 4

// 5 6 12
// 1 1 1 0 0
// 0 1 7
// 1 4 5
// 0 2 6
// 2 3 6
// 3 4 2
// 2 4 6