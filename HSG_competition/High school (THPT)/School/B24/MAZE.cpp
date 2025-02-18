#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define pii pair<ll, int>
#define fi first
#define se second

int n, m, k ,q;
const int maxn = 12;
const int maxm = (int)1e4 + 2;
char board[maxn][maxm];
vector<vector<pii>> a(maxn * maxm + 1);

int dx[4] = {0, -1, 1, 0},
    dy[4] = {-1, 0, 0, 1};

int get_node(int i, int j){
    return (i - 1) * m + j;
}

void init_graph(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(board[i][j] != '.') continue;
            int u = get_node(i, j);

            for(int x = 0; x < 4; x++){
                int i1 = i + dy[x];
                int j1 = j + dx[x];

                if(i1 < 1 || i1 > n || j1 < 1 || j1 > m || board[i1][j1] != '.') continue;
                int v = get_node(i1, j1);
                a[u].push_back({1, v});
            }
        }
    }
    return;
}

void dijkstra(int x, int y){
    vector<ll> dis(n * m + 1, LLONG_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, x});
    dis[x] = 0;

    while(!pq.empty()){
        ll w = pq.top().fi;
        int u = pq.top().se;
        pq.pop();

        if(w > dis[u]) continue;

        for(pii cur : a[u]){
            int v = cur.se;
            ll w = cur.fi;

            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
    cout<<(dis[y] != LLONG_MAX ? dis[y] : -1)<<el;
    return;
}

int main(){
    freopen(".\\txt\\MAZE.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k>>q;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin>>board[i][j];

    init_graph();

    for(int i = 1; i <= k;i++){
        int x, y, c, d, w;
        cin>>x>>y>>c>>d>>w;
        int u = get_node(x, y);
        int v = get_node(c, d);
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }

    while(q--){
        int x, y, u, v;
        cin>>x>>y>>u>>v;

        int st = get_node(x, y);
        int en = get_node(u, v);

        dijkstra(st, en);
    }
    return 0;
}