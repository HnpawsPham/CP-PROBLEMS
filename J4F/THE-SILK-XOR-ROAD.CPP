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
ll sum[maxn] = {0};

ll dfs(int u, int parent){
    for(auto [w, v] : a[u]){
        if(v == parent) continue;
        sum[v] = sum[u] ^ w;
        dfs(v, u);
    }
    return sum[u];
}

int main(){
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

    ll res = 0;
    for(int i = 0; i <= 26; i++){
        int cnt1 = 0;
        for(int j = 1; j <= n; j++)
            if(sum[j] >> i & 1) cnt1++;

        res += (1 << i) * 1LL * cnt1 * 1LL * (n - cnt1);
    }
    cout<<res;
    return 0;
}

// 4
// 1 2 3
// 2 3 5
// 2 4 6
