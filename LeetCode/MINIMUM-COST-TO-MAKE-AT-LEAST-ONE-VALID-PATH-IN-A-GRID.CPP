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
int dy[4] = {-1, 0, 0, 1},
    dx[4] = {0, -1, 1, 0},
    sign[4] = {4, 2, 1, 3};

bool check(int i, int j){
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int id(int i, int j){
    return i * m + j;
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
    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>a[i][j];

    vector<pii> ed[id(n, m)];
    for(int i= 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int x = 0; x < 4; x++){
                int i1 = i + dy[x];
                int j1 = j + dx[x];

                if(check(i1, j1))
                ed[id(i, j)].push_back({(a[i][j] != sign[x]), id(i1, j1)});
            }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dis(id(n, m), n * m + 5);
    pq.push({0, id(0, 0)});
    dis[id(0, 0)] = 0;

    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        if(u == id(n - 1, m - 1)) break;
        if(w > dis[u]) continue;

        for(auto [w, v] : ed[u]){
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
    cout<<dis[id(n - 1, m - 1)];
    return 0;
}

// 4 4
// 1 1 1 1
// 2 2 2 2
// 1 1 1 1
// 2 2 2 2