#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;
const int maxn = 1e5 + 5;
vector<pii> a[maxn];
vi res;

bool dfs(int u, int parent){
    bool bel = 0;
    for(auto [v, t] : a[u]){
        if(v == parent) continue;
        bool found = dfs(v, u);
        if(t == 2 && !found) res.push_back(v);
        if(t == 2 || found) bel = 1;
    }
    return bel;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i < n; i++){
        int u, v, t;
        cin>>u>>v>>t;
        a[u].push_back({v, t});
        a[v].push_back({u, t});
    }
    dfs(1, 0);
    
    cout<<res.size()<<el;
    for(int x : res) cout<<x<<" ";
    return 0;
}