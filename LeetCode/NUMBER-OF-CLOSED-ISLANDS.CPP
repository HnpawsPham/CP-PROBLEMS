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
const int maxn = 105 * 105;
int parent[maxn], sz[maxn];

int dy[4] = {-1, 1, 0, 0},
    dx[4] = {0, 0, -1, 1};

void makeset(){
    for(int i = 0; i < n * m; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool unite(int u, int v){
    u = find(u);
    v = find(v);
    
    if(u== v) return 0;
    if(sz[u] < sz[v]) swap(u, v);

    sz[u] += sz[v];
    parent[v] = u;
    return 1;
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
    vector<vi> a(n, vi(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>a[i][j];

    makeset();
    bool bound[n * m + 1];
    memset(bound, 0, sizeof bound);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(a[i][j]){
                parent[id(i, j)] = -1;
                continue;
            }

            for(int x = 0; x< 4; x++){
                int i1 = i + dy[x];
                int j1 = j + dx[x];

                if(i1 < 0 || j1 < 0 || i1 == n || j1 == m || a[i1][j1])
                    continue;

                unite(id(i, j), id(i1, j1));  
            }
        }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(!a[i][j])
                if(i == n - 1 || i == 0 || j == 0 || j == m - 1)
                    bound[find(id(i, j))] = 1;
        }

    int cnt = 0;
    for(int i = 0; i < n * m; i++)
        if(parent[i] == i && !bound[i]) cnt++;
    cout<<cnt;
    return 0;
}

// 5 8
// 1 1 1 1 1 1 1 0
// 1 0 0 0 0 1 1 0
// 1 0 1 0 1 1 1 0
// 1 0 0 0 0 1 0 1
// 1 1 1 1 1 1 1 0