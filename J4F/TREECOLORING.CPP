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

int n;
const int maxn = 1e5 + 5;
vector<pii> a[maxn];
bool color[maxn] = {0};

void dfs(int u, int parent){
    for(auto [w, v] : a[u]){
        if(v == parent) continue;
        
        if(w % 2) color[v] = !color[u];
        else color[v] = color[u];
        dfs(v, u);
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

    cin>>n;
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }

    dfs(1, 0);
    for(int i = 1; i <= n; i++)
        cout<<color[i]<<" ";
    return 0;
}