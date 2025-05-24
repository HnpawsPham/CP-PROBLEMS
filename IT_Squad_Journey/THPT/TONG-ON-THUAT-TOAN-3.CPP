#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define pii pair<int, int>
#define fi first
#define se second

struct line{
    int u, v ,w;
    line(int u1, int v1, int w1) : u(u1), v(v1), w(w1) {};
};

int n, m;
const int maxn = 1e5 + 4;
const int oo = INT_MAX;
vector<vector<int>> a(maxn);
vector<line> g;

bool check[maxn];
vector<int> topo;

void dfs(int u){
    check[u] = 1;
    for(int v : a[u])
        if(!check[v])
            dfs(v);
    
    topo.push_back(u);
    return;    
}

void bfs(int st){
    queue<int> q;
    q.push(st);
    check[st] = 1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : a[u])
            if(!check[v]){
                check[v] = 1;
                q.push(v);
            }
    }
    return;
}

// void dijkstra(int st, int en){
//     vector<int> dis(n, oo);
//     int parent[n + 1];
//     priority_queue<pii, vector<pii>, greater<pii>> pq;
//     pq.push({0, st});
//     parent[st] = st;
//     dis[st] = 0;

//     while(!pq.empty()){
//         auto [u, w] = pq.top();
//         pq.pop();

//         if(w > dis[u]) continue;

//         for(auto [w1, v]: a[u]){
//             if(dis[u] != oo && dis[u] + w1 < dis[v]){
//                 dis[v] = dis[u] + w1;
//                 pq.push({dis[v], v});
//                 parent[v] = u;
//             }
//         }
//     }
//     cout<<dis[en];
//     deque<int> path;

//     while(en != st){
//         path.push_front(en);
//         en = parent[en];
//     }

//     for(int x : path) cout<<x<<" ";
//     return;
// }

int id = 0, scc = 0;
int low[maxn], idx[maxn] = {0};
stack<int> path;

void tarjan(int u){
    low[u] = idx[u] = id++;
    check[u] = 1;
    path.push(u);
    
    for(int v : a[u]){
        if(!idx[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(check[v])
            low[u] = min(low[u], idx[v]);
    }

    if(low[u] == idx[u]){
        scc++;
        while(1){
            int v = path.top();
            path.pop();

            check[v] = 0;

            if(u == v) break;
        }
    }
    return;
}

int sz[maxn];
int parent[maxn];

void make_set(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
    return;
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool union_set(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return 0;
    if(sz[a] < sz[b]) swap(a, b);
    
    parent[b] = a;
    sz[a] += sz[b];

    return 1;
}

bool comp(line a, line b){
    return a.w < b.w;
}

void kruskal(){
    int d = 0;
    vector<line> mst;
    sort(a.begin(), a.end(), comp);

    for(int i = 0; i < m; i++){
        if(mst.size() == n - 1) break;

        if(union_set(g[i].u, g[i].v)){
            mst.push_back(g[i]);
            d += g[i].w;
        }
    }

    cout<<d<<el;
    for(line x : mst)
        cout<<x.u<<" "<<x.v<<el;

    return;
}

bool color[maxn];
bool dfs_2phia(int u, int parent){
    color[u] = 1 - color[parent];

    for(int v : a[u]){
        if(!color[v])
            if(!dfs_2phia(v, u))
                return 0;
        else if(color[u] == color[v]) return 0;
    }
    return 1;
}

int bridge = 0;
void canh_cau(int u, int parent){
    low[u] = idx[u] = id++;

    for(int v : a[u]){
        if(!idx[v]){
            canh_cau(v, u);
            low[u] = min(low[v], low[u]);

            if(low[v] > idx[u]) bridge++;
        }
        else if(v != parent)
            low[u] = min(low[u], idx[v]);
    }
    return;
}

void manacher(string t){
    string s = "";

    for(char x : t)
        s = s + '|' + x;
    s += '|';
    int n = s.length();

    int p[n] = {0};
    int c = 0, r = 0, res = 0;

    for(int i = 1; i < n; i++){
        if(i < r)
            p[i] = min(p[2 * c - i], r - i);
        
        while(i + p[i] < n && s[i + p[i]] == s[i - p[i]])
            p[i]++;
        
        if(i + p[i] > r){
            r = i + p[i];
            c = i;
        }
        res = max(res, p[i] - 1);
    }
    cout<<res;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    while(m--){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
    }

    dfs(1);
    // reverse(topo.begin(), topo.end());

    int dp[n + 1] = {0};
    int res = 0;

    for(int u : topo){
        for(int v : a[u])
            dp[u] = max(dp[u], dp[v] + 1);
        res = max(res, dp[u]);
    }
    cout<<res;

    return 0;
}