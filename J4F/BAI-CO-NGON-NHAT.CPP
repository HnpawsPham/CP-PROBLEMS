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
const int maxn = 1e5 + 5;
int parent[maxn], sz[maxn];

int dy[4] = {-1, 0, 0, 1},
    dx[4] = {0, -1, 1, 0};

int id(int i, int j){
    return i * m + j;
}

void makeset(){
    for(int i = 0; i < maxn; i++){
        sz[i] = 1;
        parent[i] = i;
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
    sz[v] = 0;
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
    string a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    makeset();

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(a[i][j] == '.') continue;
        
            for(int x = 0;x < 4; x++){
                int i1 = i + dy[x];
                int j1 = j + dx[x];

                if(i1 < 0 || j1 < 0 || i1 == n || j1 == m || a[i1][j1] == '.')
                    continue;

                unite(id(i, j), id(i1, j1));
            }
        }

    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] == '#' && find(id(i, j)) == id(i, j)) cnt++;
    cout<<cnt;
    return 0;
}