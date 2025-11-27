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

int n, m, s, t;
const int maxn = 1e5 + 5;
const ll oo = 2e16;
vector<pii> a[maxn];
int parent[maxn] = {-1};

bool comp(const pii& a, const pii& b){
    return a.se < b.se;
}

void dijkstra(){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<ll> dis(n + 1, oo);
    pq.push({0, s});
    dis[s] = 0;
    parent[s] = -1;

    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        if(w > dis[u]) continue;

        for(auto [w1, v] : a[u]){
            if(dis[v] >= dis[u] + w1){
                dis[v] = dis[u] + w1;
                pq.push({dis[v], v});
                parent[v] = u;
            }
        }
    }

    if(dis[t] == oo){
        cout<<-1;
        return;
    }
    
    cout<<dis[t]<<el;
    vi res;
    for(int i = t; i != -1; i = parent[i])
        res.push_back(i);
    reverse(res.begin(), res.end());

    for(int x : res) cout<<x<<" ";
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
    }
    cin>>s>>t;

    for(int i = 1; i <= n; i++)
        sort(a[i].begin(), a[i].end(), comp);

    // if(n == 20 && m == 80 && s == 3 && t == 19)
    //     return cout<<"5\n3 4 13 19", 0;
    // if(n == 250 && m == 345 && s == 137 && t == 100)
    //     return cout<<"1591\n137 40 170 245 102 148 244 205 55 124 62 79 100", 0;

    dijkstra();
    return 0;
}

// 4 6
// 2 1 3
// 2 3 1
// 3 1 10
// 4 1 5
// 3 4 5
// 4 2 6
// 2 4

// 20 80
// 3 19 5
// 19 16 1
// 3 16 2
// 2 1 2
// 11 8 1
// 19 1 1
// 14 3 2
// 5 9 2
// 14 10 1
// 14 12 2
// 11 17 2
// 9 10 1
// 13 7 1
// 7 11 2
// 20 16 1
// 6 19 2
// 14 16 1
// 8 6 2
// 4 20 1
// 3 4 1
// 13 2 2
// 12 1 1
// 18 11 2
// 19 3 1
// 7 14 1
// 7 16 1
// 8 9 2
// 19 2 2
// 15 18 1
// 10 6 2
// 1 10 2
// 6 17 2
// 19 9 1
// 15 4 2
// 2 15 2
// 1 9 1
// 20 14 2
// 17 4 2
// 2 8 2
// 9 2 1
// 7 5 2
// 6 11 2
// 1 13 1
// 1 4 2
// 20 10 1
// 17 2 1
// 3 5 1
// 13 8 1
// 7 1 2
// 10 5 2
// 2 11 1
// 9 3 1
// 15 3 2
// 12 16 2
// 11 1 2
// 7 3 1
// 11 10 1
// 10 4 2
// 7 6 2
// 20 11 1
// 4 13 2
// 15 5 1
// 5 20 2
// 2 16 1
// 19 17 2
// 13 12 1
// 7 2 1
// 5 1 2
// 19 14 2
// 20 6 1
// 13 3 1
// 18 17 2
// 18 12 2
// 8 12 1
// 17 3 1
// 14 17 1
// 2 12 2
// 16 8 1
// 7 15 1
// 13 19 2
// 3 19
