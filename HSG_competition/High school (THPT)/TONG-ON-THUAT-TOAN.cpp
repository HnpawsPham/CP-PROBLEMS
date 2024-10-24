#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int, int>

const int maxn = (int) 1e5 + 5;
bool kngto[maxn];

// SANG SO NGTO
void sieve(){
    kngto[0] = kngto[1] = 1;

    for(int i = 2; i < sqrt(maxn); i++){
        if(!kngto[i])
            for(int j = i + i; j <= maxn; j+=i) kngto[j] = 1;
    }
    return;
}

// 2D PREFIX SUM
void init2DPre(){
    int n = 3, m = 2;
    int a[n + 1][m + 1] = {{0, 0, 0}, {0, 1, 2}, {0, 4, 5}, {0, 2, 1}};
    int p[n + 1][m + 1];

    for(int i = 0;i <=n;i++)
        for(int j = 0; j <=m;j++) p[i][j] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <=m;j++)
            p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + a[i][j];
        

    for(int i = 1; i <= n;i++){
        for(int j = 1; j <= m; j++) cout<<p[i][j]<<" ";
        cout<<el;
    }
    return;
}

// DFS
bool check[maxn];
vector<vector<int>> a(maxn);
deque<int> topo;

void dfs(int u){
    check[u] = true;

    for(int v : a[u])
        if(!check[v]) dfs(v);

    topo.push_front(u);
    return;
}

// BFS
void bfs(int x){
    queue<int> q;
    q.push(x);
    check[x] = true;

    while(!q.empty()){
        int u = q.front(); q.pop();

        for(int v : a[u]){
            if(check[v]) continue;

            q.push(v);
            check[v] = 1;
        }
    }
    return;
}

// KAHN
int in[maxn];
void kahn(){
    int n = 10;
    queue<int> q;
    
    for(int i = 1; i<=n; i++){
        if(in[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int u = q.front(); q.pop();
        topo.push_back(u);

        for(int v : a[u]){
            in[v]--;
            if (in[v] == 0) q.push(v);
        }
    }
    return;
}

// DIJKSTRA
void dijkstra(int x, int en, int st){
    int n = 10;
    int parent[n + 1];
    vector<vector<pii>> a(n + 1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dis(n, INT_MAX);

    pq.push({0, x});
    dis[x] = 0;

    while(!pq.empty()){
        pii cur = pq.top(); pq.pop();
        int u = cur.second;
        int w = cur.first;

        if(w > dis[u]) continue;

        for(pii x : a[u]){
            int v = x.second;
            int w1 = x.first;

            if(dis[u] != INT_MAX && dis[u] + w1 < dis[v]){
                dis[v] = dis[u] + w1;
                pq.push({v, dis[v]});
                parent[v] = u;
            }
        }
    }

    deque<int> path;
    
    cout<<dis[en]<<el;
    while(en != st){
        path.push_front(en);
        en = parent[en];
    }
    path.push_front(st);

    for(int x : path) cout<<x<<" ";
    cout<<el;

    return;
}

// BELLMAN FORD
struct line{
    int u, v, w;
    line(int u1, int v1, int w1) : u(u1), v(v1), w(w1) {};
};

vector<line> c;

void bellmanFord(){
    int st = -1;
    int n = 10;
    int parent[n + 1];
    vector<int> dis(n + 1, INT_MAX);

    for(int i = 0; i < n && st; i++){
        st = 0;
        for(line l : c){
            if(dis[l.u] != INT_MAX && dis[l.u] + l.w < dis[l.v]){
                dis[l.v] = dis[l.u] + l.w;
                st = l.v;
                parent[l.v] = l.u;
            }
        }
    }

    if(!st) return;

    for(int i = 0; i < n;i++) st = parent[st];
    deque<int> path;
    int en = st;

    while(en != st){
        path.push_front(en);
        en = parent[en];
    }
    path.push_front(st);
    path.push_back(st);

    for(int x : path) cout<<x<<" ";
    cout<<el;
    return;
}

// TARJAN
int id = 0;
int index[maxn], low[maxn];
stack<int> tjpath;

void tarjan(int u){
    tjpath.push(u);
    check[u] = true;
    low[u] = index[u] = id++;

    for(int v : a[u]){
        if(index[v] == 0){
            tarjan(v);
            low[v] = min(low[u], low[v]);
        }
        else if(check[v]){
            low[u] = min(low[u], index[v]);
        }
    }

    if(index[u] == low[u]){
        while(true){
            int v = tjpath.top(); tjpath.pop();

            low[v] = low[u];
            check[v] = 0;

            if(v == u) break;
        }
    }
    return;
}

// DSU
int n = 10;
int dsuParent[maxn];
int sz[maxn];

void makeSet(){
    for(int i = 1; i <=n;i++){
        dsuParent[i] = i;
        sz[i] = 1;        
    }
    return;
}

int find(int x){
    if(x == dsuParent[x]) return x;
    return dsuParent[x] = find(dsuParent[x]);
}

bool unionSet(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return false;
    if(sz[a] < sz[b]) swap(a, b);
    dsuParent[b] = a;
    sz[a] += sz[b];
    sz[b] = 0;

    return true;
}

// KRUSKAL
bool compare(line a, line b){
    return a.w < b.w;
}

vector<line> ka;
void kruskal(){
    int m = 10;
    vector<line> mst;
    int msize = 0;

    sort(a.begin(), a.end(), compare);

    for(int i = 0; i < m;i++){
        if(mst.size() == n - 1) break;

        if(unionSet(ka[i].u, ka[i].v)){
            mst.push_back(ka[i]);
            msize += ka[i].w;
        }
    }

    if(mst.size() != n - 1) return;

    for(line l : mst) cout<<l.u<<" "<<l.v<<el;
    return;
}

// CANH CAU
vector<pii> ans;

void canhcau(int u, int parent){
    low[u] = index[u] = id++;

    for(int v : a[u]){
        if(!index[v]){
            canhcau(v, u);
            low[v] = min(low[v], low[u]);

            if(low[v] > index[u]) ans.push_back({u, v});
        }
        else if(v != parent)
            low[u] = min(low[u], index[v]);
    }
    return;
}

// KIEM TRA DINH KHOP
vector<int> res;
void khop(int u, int parent){
    index[u] = low[u] = id++;
    
    for(int v : a[u]){
        if(!index[v]){
            khop(v, u);
            low[v] = min(low[v], low[u]);

            if(parent != 0 && low[v] >= index[u]) res.push_back(u);
        }
        else if(v != parent) low[u] = min(low[u], index[v]);
    }

    if(parent == 0 && res.size() > 1) res.push_back(u);
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sieve();
    init2DPre();

    return 0;
}