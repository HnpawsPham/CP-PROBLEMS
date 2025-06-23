#include <bits/stdc++.h>
using namespace std;
#define el "\n"

const int maxn = 2e5 + 5;
vector<int> a[maxn];
int n;
int dp[maxn][2];

void dfs(int u, int parent){
    int sum = 0;
    for(int v : a[u]){
        if(v == parent) continue;
        dfs(v, u);
        sum += max(dp[v][0], dp[v][1]);
    }

    dp[u][0] = sum;

    for(int v : a[u])
        if(v != parent)
            dp[u][1] = max(dp[u][1], sum - max(dp[v][0], dp[v][1]) + dp[v][0] + 1);
    return;
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
    dp[1][1] = dp[1][0] = 0;
    
    dfs(1, 0);
    cout<<max(dp[1][0], dp[1][1]);
    return 0;
}