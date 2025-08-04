#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m, Q;
const int maxn = 1e5 + 3;
vector<vi> a(maxn);
int color[maxn] = {0}, check[maxn][11];

void dfs(int u, int d, int c){
    if(check[u][d]) return;
    check[u][d] = 1;

    if(!color[u]) color[u] = c;
    if(d == 0) return;

    for(int v : a[u])
        dfs(v, d - 1, c);
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
        a[v].push_back(u);
    }

    cin>>Q;
    vector<vi> q(Q);
    for(int i = 0; i < Q; i++){
        int u, d, c;
        cin>>u>>d>>c;
        q[i] = {u, d, c};
    }

    for(int i = Q - 1; i >= 0; i--){
        int u = q[i][0], d = q[i][1], c = q[i][2];
        dfs(u, d, c);
    }

    for(int i = 1; i <= n; i++) cout<<color[i]<<el;
    return 0;
}

// 7 7
// 1 2
// 1 4
// 2 3
// 3 6
// 4 5
// 5 6
// 6 7
// 3
// 7 3 1
// 5 1 2
// 5 0 3