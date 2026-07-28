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
#define taskname "THAMQUAN"

int n, m;
const int maxn = 1e5 + 5;
int w[maxn], low[maxn], idx[maxn] = {0}, id = 0;
vi a[maxn];
bool inStack[maxn] = {0};
stack<int> st;

int scc = 0;
int sccId[maxn];
ll sccSum[maxn] = {0};
vi g[maxn];

void dfs(int u){
    low[u] = idx[u] = ++id;
    st.push(u);
    inStack[u] = 1;

    for(int v : a[u]){
        if(!idx[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(inStack[v])
            low[u] = min(low[u], idx[v]);
    }

    if(low[u] == idx[u]){
        scc++;
        while(1){
            int v = st.top();
            st.pop();

            sccId[v] = scc;
            inStack[v] = 0;
            sccSum[scc] += w[v];

            if(u == v) break;
        }
    }
}

vi topo;
bool check[maxn] = {0};
void toposort(int u){
    check[u] = 1;

    for(int v : g[u])
        if(!check[v]) toposort(v);

    topo.push_back(u);
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
    for(int i= 1; i <= n; i++) cin>>w[i];
    while(m--){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
    }

    for(int i = 1; i <= n; i++)
        if(!idx[i]) dfs(i);

    for(int i = 1; i <= n; i++)
        for(int v : a[i])
            if(sccId[v] != sccId[i])
                g[sccId[i]].push_back(sccId[v]);

    for(int i = 1; i <= scc; i++)
        if(!check[i]) toposort(i);

    ll dp[scc + 1];
    for(int i = 1; i <= scc; i++)
        dp[i] = sccSum[i];

    for(int u : topo)
        for(int v : g[u])
            dp[u] = max(dp[u], dp[v] + sccSum[u]);
    
    cout<<*max_element(dp + 1, dp + scc + 1);
    return 0;
}