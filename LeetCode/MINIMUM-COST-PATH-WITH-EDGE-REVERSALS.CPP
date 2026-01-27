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
const int maxn = 5e4 + 5;
const int oo = INT_MAX;
vector<pii> a[maxn];

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    vector<vi>ed(m, vi(3));
    for(int i = 0; i < m; i++)
        cin>>ed[i][0]>>ed[i][1]>>ed[i][2];

    set<pii> rev;
    for(const vi &v : ed){
        a[v[0]].push_back({v[2], v[1]});
        a[v[1]].push_back({2 * v[2], v[0]});
        rev.insert({v[1], v[0]});
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vi dis(n, oo);
    dis[0] = 0;
    pq.push({dis[0], 0});

    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        if(w > dis[u]) continue;

        for(auto [w1, v] : a[u])
            if(dis[v] > dis[u] + w1){
                dis[v] = dis[u] + w1;
                pq.push({dis[v], v});
            }
        
        for(auto [_, v] : a[u])
            if(rev.find({u, v}) != rev.end())
                rev.erase(rev.find({u, v}));
    }

    if(dis[n - 1] == oo) cout<<-1;
    else cout<<dis[n - 1];
    return 0;
}

// 4 4
// 0 1 3
// 3 1 1
// 2 3 4
// 0 2 2

// 4 4
// 0 2 1
// 2 1 1
// 1 3 1
// 2 3 3