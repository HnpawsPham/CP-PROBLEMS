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
const int maxn = 5005;
vi a[maxn];
int sz[maxn];

int dfs(int u, int parent){
    sz[u] = 1;
    for(int v : a[u]){
        if(v == parent) continue;
        sz[u] += dfs(v, u);
    }
    return sz[u];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    bool dp[n + 1], check[n + 1] = {0};
    vi res;

    for(int i = 1; i <= n; i++){
        dfs(i, 0);
        memset(dp, 0, sizeof dp);
        dp[0] = 1;

        for(int v : a[i])
            for(int j = n; j >= sz[v]; j--)
                if(dp[j - sz[v]]) dp[j] = 1;

        for(int i = 1; i < n - 1; i++)
            if(dp[i] && !check[i]) {
                res.push_back(i);
                check[i] = 1;
            }
        }

    sort(res.begin(), res.end());
    cout<<res.size()<<el;
    for(int x : res)
        cout<<x<<" "<<n - x - 1<<el;
    return 0;
}