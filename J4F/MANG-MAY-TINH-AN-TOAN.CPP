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
const int maxn = 3e5 + 5;
vi a[maxn];
int idx[maxn] = {0}, low[maxn], id = 0;
stack<int> st;
int res = 1;

void dfs(int u, int parent){
    idx[u] = low[u] = ++id;
    st.push(u);

    for(int v : a[u]){
        if(v == parent) continue;
        
        if(idx[v]) low[u] = min(low[u], idx[v]);
        else{
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            if(low[v] >= idx[u]){
                int cnt = 1;
                while(1){
                    int x = st.top();
                    st.pop();
                    cnt++;
                    if(x == v) break;
                }
                res = max(res, cnt);
            }
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
        a[v].push_back(u);
    }

    for(int i = 1; i <= n; i++)
        if(!idx[i]) dfs(i, 0);
    cout<<res;
    return 0;
}