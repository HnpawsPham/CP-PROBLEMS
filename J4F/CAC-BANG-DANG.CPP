#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m;
const int maxn = 1005;
int parent[maxn], sz[maxn];

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);

    sz[a] += sz[b];
    parent[b] = a;
    sz[b] = 0;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }

    char opt;
    int u, v;
    bool e[n + 1][n + 1] = {0};
    while(m--){
        cin>>opt>>u>>v;
        if(opt == 'F') unite(u, v);
        else e[u][v] = e[v][u] = 1; 
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(e[i][j]) 
                for(int k = 1; k <= n; k++)
                    if(e[j][k]) unite(i, k);

    int cnt = 0;
    for(int i = 1; i <= n; i++)
        if(sz[i]) cnt++;
    cout<<cnt;
    return 0;
}