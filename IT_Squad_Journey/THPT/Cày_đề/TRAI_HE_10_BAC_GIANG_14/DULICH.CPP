#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define pii pair<int, int>
#define fi first
#define se second

int n, m;
ll res = LLONG_MAX;
const int maxn = 105;
vector<vector<pii>> a(maxn);

void dfs(int u, int parent, int cnt, ll sum){
    if(cnt > n || sum > res) return;

    for(pii x : a[u]){
        int v = x.se;
        int w = x.fi;

        if(v == parent){
            res = min(res, sum + w);
            return;
        }
        else dfs(v, u, cnt + 1, sum + w);
    }
    return;
}

int main(){
    freopen("DULICH.INP","r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }
    for(int i = 1; i <= n; i++) dfs(i, 0, 0, 0);
    cout<<res;

    return 0;
}