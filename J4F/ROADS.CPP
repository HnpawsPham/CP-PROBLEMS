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

struct ed{
    int v, w, val;
    ed() {};
    ed(int v1, int w1, int val1) : v(v1), w(w1), val(val1) {};

    bool operator>(const ed& other) const {
        if(w != other.w) return w > other.w;
        return val > other.val;
    }
};

int tc = 1;
int k, n, m;
const int maxn = 105;
const int oo = 1e5 + 5;
vector<ed> a[maxn];

int dijkstra(){
    vector<vi> dis(n + 1, vi(k + 1, oo));
    priority_queue<ed, vector<ed>, greater<ed>> pq;
    dis[1][k] = 0;
    pq.push({1, 0, k});

    while(!pq.empty()){
        auto [u, w, budget] = pq.top();
        pq.pop();

        if(w > dis[u][budget]) continue;
        
        for(auto [v, w1, val] : a[u]){
            if(budget - val >= 0 && dis[v][budget - val] > dis[u][budget] + w1){
                dis[v][budget - val] = dis[u][budget] + w1;
                pq.push({v, dis[v][budget - val], budget - val});
            }
        }
    }
    int res = *min_element(dis[n].begin(), dis[n].end());
    return (res != oo ? res : -1);
}

int sol(){
    cin>>k>>n>>m;
    for(int i = 0; i < maxn; i++)
        a[i].clear();

    while(m--){
        int u, v, w, val;
        cin>>u>>v>>w>>val;
        a[u].push_back({v, w, val});
    }
    return dijkstra();
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}