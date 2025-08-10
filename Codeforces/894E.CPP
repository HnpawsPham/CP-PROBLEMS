#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m, st;
const int maxn = 1e6 + 5;
vector<vector<pii>> a(maxn), ed;

bool valid(int w, int k){
    return w - 1LL * k * (k - 1) / 2 >= 0; 
}

ll calc_w(int w){
    int l = 1, r = maxn, mid, k = 0;
    while(l <= r){
        mid = (l + r) / 2;

        if(valid(w, mid)) {
            l = mid + 1;
            k = mid;
        }
        else r = mid - 1;
    }

    return 1LL * k * w - (1LL * k * (k + 1) * (k - 1) / 6);
}

int idx[maxn] = {0}, low[maxn], id = 0, sccCnt = 0;
int sccId[maxn] = {0};
ll sccW[maxn] = {0};
bool onstack[maxn] = {0};
stack<int> stk;

void tarjan(int u){
    idx[u] = low[u] = ++id;
    stk.push(u);
    onstack[u] = 1;

    for(auto [w, v] : a[u]){
        if(!idx[v]){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(onstack[v])
            low[u] = min(idx[v], low[u]); 
    }

    if(low[u] == idx[u]){
        sccCnt++;

        while(1){
            int v = stk.top();
            stk.pop();

            onstack[v] = 0;
            sccId[v] = sccCnt;

            if(v == u) break;
        }
    }
    return;
}

vector<vector<pii>> sccGr(maxn);
void build(){
    for(int u = 1; u <= n; u++){
        for(auto [w, v] : a[u])
            if(sccId[u] != sccId[v])
                sccGr[sccId[u]].push_back({w, sccId[v]});
            else sccW[sccId[u]] += calc_w(w);
    }
    return;
}

vi topo;
bool check_scc[maxn] = {0};

void toposort(int u){
    check_scc[u] = 1;

    for(auto [w, v] : sccGr[u])
        if(!check_scc[v])
            toposort(v);

    topo.push_back(u);
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
    }

    cin>>st;

    for(int i = 1; i <= n; i++)
        if(!idx[i]) tarjan(i);

    build();
    toposort(sccId[st]);
    reverse(topo.begin(), topo.end());

    ll dp[sccCnt + 1] = {0};
    for(int u : topo){
        dp[u] += sccW[u];

        for(auto [w, v] : sccGr[u])
            dp[v] = max(dp[v], 1LL * dp[u] + w);
    }
    cout << *max_element(dp, dp + sccCnt + 1);
    return 0;
}