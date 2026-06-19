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
const int maxn = 805;
vi a[maxn];

int id = 0, scc = 0;
int low[maxn], idx[maxn] = {0};
stack<int> st;
bool inStack[maxn] = {0};

int sccId[maxn] = {0}, in[maxn] = {0};

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

            if(u == v) break;
        }
    }
    return;
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
    while(m--){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
    }
    
    for(int i = 1; i <= n; i++)
        if(!idx[i]) dfs(i);
    
    for(int u = 1; u <= n; u++)
        for(int v : a[u])
            if(sccId[u] != sccId[v]) in[sccId[v]]++;

    int cnt = 0;
    for(int i = 1; i <= scc; i++)
        if(!in[i]) cnt++;
    cout<<cnt;
    return 0;
}