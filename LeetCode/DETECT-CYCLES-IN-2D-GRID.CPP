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

const int maxn = 25e4 + 5;
int n, m;

int dx[4] = {0, 1, 0, -1},
    dy[4] = {1, 0, -1, 0};
// bool check[maxn][maxn], met[maxn][maxn];

// bool bfs(int i, int j, vector<vector<char>>& a){
//     memset(check, 0, sizeof check);
//     queue<pair<pii, pii>> q;
//     q.push({{i, j}, {-1, -1}});
//     check[i][j] = met[i][j] = 1;

//     while(!q.empty()){
//         auto [cur, p] = q.front();
//         q.pop();

//         auto [u, v] = cur;

//         for(int x = 0; x < 4; x++){
//             int i1 = u + dy[x];
//             int j1 = v + dx[x];

//             if(i1 < 0 || i1 == n || j1 < 0 || j1 == m || a[i1][j1] != a[u][v]) 
//                 continue;

//             if(check[i1][j1]){
//                 if(i1 != p.fi || j1 != p.se) return 1;
//             }
//             else{
//                 q.push({{i1, j1}, {u, v}});  
//                 check[i1][j1] = met[i1][j1] = 1;   
//             } 
//         }
//     }
//     return 0;
// }

int id(int i, int j){
    return i * m + j;
}

int parent[maxn], sz[maxn];
void makeset(){
    for(int i = 0; i < maxn; i++){
        parent[i] = i;
        sz[i] = 1;
    }
    return;
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool unite(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return 0;
    if(sz[u] < sz[v]) swap(u, v);

    sz[u] += sz[v];
    parent[v] = u;
    return 1;
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
    vector<vector<char>> a(n, vector<char>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>a[i][j];

    // for(int i = 0; i < n; i++)
    //     for(int j = 0; j < m; j++){
    //         if(met[i][j]) continue;
    //         if(bfs(i, j, a)) return cout<<1, 0;
    //     }
    // cout<<0;

    makeset();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            for(int x = 0; x < 4; x++){
                int i1 = i + dy[x];
                int j1 = j + dx[x];

                if(i1 < 0 || j1 < 0 || i1 == n || j1 == m || a[i][j] != a[i1][j1])
                    continue;

                if(!unite(id(i, j), id(i1, j1))) 
                    return cout<<1, 0;
            }
            a[i][j] = '_';
        }
    cout<<0;
    return 0;
}

// 4 4
// a a a a 
// a b b a
// a b b a
// a a a a

// 3 3
// a b b 
// b z b
// b b a