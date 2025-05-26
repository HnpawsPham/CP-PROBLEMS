#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>

string s;
int n, m;
const int maxn = 1e5;
vector<vi> a(maxn), edge;
vi topo;
int check[maxn] = {0};

bool dfs(int u){
    check[u] = 1;

    for(int v : a[u]){
        if(check[v] == 1) return 1;
        if(check[v] == 0 && dfs(v)) return 1;
    }
    check[u] = 2;
    topo.push_back(u);
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>m;
    n = s.length();

    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        edge.push_back({u, v});
    }

    for(const vi& v : edge)
        a[v[0]].push_back(v[1]);

    for(int i = 0; i < n; i++)
        if(!check[i])
            if(dfs(0)) return cout<<-1, 0;

    vector<vi> dp(n, vi(26, 0));
    int res = 0;
    reverse(topo.begin(), topo.end());

    for(int u : topo){
        dp[u][s[u] - 'a']++;
        res = max(res, dp[u][s[u] - 'a']);

        for(int v : a[u]){
            for(int i = 0; i < 26; i++)
                dp[v][i] = max(dp[v][i], dp[u][i]);
        }
    }
    cout<<res;
    return 0;
}