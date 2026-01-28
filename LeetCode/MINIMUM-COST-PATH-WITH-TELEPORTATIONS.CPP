#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define piii pair<int, pii>
#define vb vector<bool>
#define fi first
#define se second
//#define taskname ""

int n, m, k;
const int maxn = 8e4 + 5;
const int oo = 1e9 + 5;
vector<pii> a[maxn];

int dx[2] = {0, 1},
    dy[2] = {1, 0};

bool check(int i, int j){
    if(i < 0 || j < 0 || i == n || j == m)
        return 0;
    return 1;
}

int node(int i, int j){
    return m * i + j;
}

pii pos(int node){
    int i = node / m;
    int j = node % m;
    return {i, j};
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    vector<vi> g(n, vi(m));
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++)
            cin>>g[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int x = 0; x < 2; x++){
                int i1 = i + dy[x];
                int j1 = j + dx[x];

                if(check(i1, j1))
                    a[node(i, j)].push_back({g[i1][j1], node(i1, j1)});
            }

    vector<pii> val;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            val.push_back({g[i][j], node(i, j)});

    sort(val.begin(), val.end());
    int sz = val.size();

    int en = node(n - 1, m - 1);
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    vector<vi> dis(en + 1, vi(k + 1, oo));
    vector<vb> check(en + 1, vb(k + 1, 0));
    dis[0][k] = 0;
    pq.push({dis[0][k], {0, k}});

    // int cur = 0;

    while(!pq.empty()){
        auto [w, state] = pq.top();
        auto [u, cnt] = state;
        pq.pop();

        if(w > dis[u][cnt]) continue;

        for(auto [w1, v] : a[u]){
            if(dis[v][cnt] > dis[u][cnt] + w1){
                dis[v][cnt] = dis[u][cnt] + w1;
                pq.push({dis[v][cnt], {v, cnt}});
            }
        }

        if(cnt > 0 && !check[u][cnt]){
            check[u][cnt] = 1;
            int cur = 0;

            while(cur < sz && val[cur].fi <= val[u].fi){
                int v = val[cur].se;
                if(dis[v][cnt - 1] > dis[u][cnt]){
                    dis[v][cnt - 1] = dis[u][cnt];
                    pq.push({dis[v][cnt - 1], {v, cnt - 1}});
                }
                cur++;
            }

            // auto [i, j] = pos(u);
            // for(int ii = 0; ii < n; ii++)
            //     for(int jj = 0; jj < m; jj++){
            
            //         if(g[ii][jj] > g[i][j]) continue;
            //         int v = node(ii, jj);

            //         if(dis[v][cnt - 1] > dis[u][cnt]){
            //             dis[v][cnt - 1] = dis[u][cnt];
            //             pq.push({dis[v][cnt - 1], {v, cnt - 1}});
            //         }
            //     }
        }
    }
    cout<<*min_element(dis[en].begin(), dis[en].end());
    return 0;
}

// 3 3 2
// 1 3 3
// 2 5 4
// 4 3 5

// 3 2 1
// 1 2
// 2 3
// 3 4