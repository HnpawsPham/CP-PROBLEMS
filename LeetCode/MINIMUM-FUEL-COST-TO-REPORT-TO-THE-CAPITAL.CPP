#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, k;
ll res = 0;
vector<vi> a;

int dfs(int u, int parent){
    int cntu = 1;

    for(int v : a[u]){
        if(v == parent) continue;
        int cntv = dfs(v, u);
        res += (cntv + k - 1) / k; // ceil(cntv / k)
        cntu += cntv;
    }
    return cntu;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    vector<vi> ed(n - 1);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin>>u>>v;
        ed[i] = {u, v};
    }

    a.resize(n);
    for(const auto& v : ed){
        a[v[0]].push_back(v[1]);
        a[v[1]].push_back(v[0]);
    }
    dfs(0, -1);
    cout<<res;
    return 0;
}