#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define fi first
#define se second
#define pil pair<int, ll>

const int maxn = 2 * (int)1e5 + 5;

int n, m, id = 0, scc_cnt = 0;
vector<vector<pil>> a(maxn), sccGr(maxn);
int low[maxn], idx[maxn], sccId[maxn];
ll sccSum[maxn], dp[maxn];
bool check[maxn], check_scc[maxn], found[maxn];  
stack <int> path;
vector<int> topo;

ll calc(ll sum){
    ll s = 0;
    while(sum > 0){
        s += sum;
        sum /= 2;
    }
    return s;
}

void dfs(int u){
    path.push(u);
    check[u] = 1;
    low[u] = idx[u] = ++id;

    for(pil x : a[u]){
        int v = x.fi;

        if(!idx[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(check[v])
            low[u] = min(low[u], idx[v]);
    }

    if(low[u] == idx[u]){
        scc_cnt++;

        while(1){
            int v = path.top();
            path.pop();
            
            check[v] = 0;
            sccId[v] = scc_cnt;

            if(u == v) break;
        }
    }
    return;
}

void init_graph(){
    for(int u = 1; u <= n; u++)
        for(pil x: a[u]){
            int v = x.fi;
            ll w = x.se;
            if(sccId[v] != sccId[u]) sccGr[sccId[u]].push_back({sccId[v], w}); 
            else sccSum[sccId[u]] += calc(w);
        }
    return;
}

void find_path(int u) {  
    found[u] = 1;
    for (pil x : sccGr[u]) {
        int v = x.fi;
        if (!found[v]) 
            find_path(v);
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u, v; ll w;
        cin>>u>>v>>w;
        a[u].push_back({v, w});
    }
    
    memset(idx, 0, sizeof(idx));

    for(int i = 1; i <= n; i++) if(!idx[i]) dfs(i);

    init_graph();
    find_path(sccId[1]); 

    ll res = 0;
    for (int u = 1; u <= scc_cnt; u++) {
        if (!found[u]) continue;
        dp[u] = 0;

        for (pil x : sccGr[u]) { 
            int v = x.fi;
            ll w = x.se;
            if (found[v]) 
                dp[u] = max(dp[u], dp[v] + w);
        }
        dp[u] += sccSum[u];
        res = max(res, dp[u]);
    }
    cout<<res;
    
    return 0;
}