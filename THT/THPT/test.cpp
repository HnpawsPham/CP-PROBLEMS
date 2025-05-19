#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

const ll oo = 1e9;
int n, k;
vector<vector<pair<int, int>>> a; 
vector<vector<ll>> dp;

void dfs(int u) {
    dp[u][0] = 0; 

    if (a[u].empty()) { 
        for (int i = 1; i <= k; i++) dp[u][i] = -oo;
        return;
    }


    for (const auto& p : a[u]) {
        dfs(p.first);
    }

    auto up_single = [&](int v, int w, int i) {
        if (i < 1) return;
        for (int j = 0; j <= i-1; j++) {
            if (dp[v][j] != -oo) {
                dp[u][i] = max(dp[u][i], dp[v][j] + w);
            }
        }
    };

    auto up_mul = [&](int v1, int w1, int v2, int w2, int i) {
        if (i < 2) return;
        for (int j = 0; j <= i-2; j++) {
            for (int m = 0; m <= i-2-j; m++) {
                if (dp[v1][j] != -oo && dp[v2][m] != -oo) {
                    dp[u][i] = max(dp[u][i], dp[v1][j] + w1 + dp[v2][m] + w2);
                }
            }
        }
    };

    for (int i = 0; i <= k; i++) {
        dp[u][i] = 0; 

        if (a[u].size() >= 1) {
            int v1 = a[u][0].first, w1 = a[u][0].second;
            up_single(v1, w1, i);
        }

        if (a[u].size() >= 2) {
            int v2 = a[u][1].first, w2 = a[u][1].second;
            up_single(v2, w2, i);
        }

        if (a[u].size() == 2) {
            int v1 = a[u][0].first, w1 = a[u][0].second;
            int v2 = a[u][1].first, w2 = a[u][1].second;
            up_mul(v1, w1, v2, w2, i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    a.resize(n + 1);


    vector<int> p(n + 1, 0); 
    p[1] = -1; 
    for (int i = 0; i < n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
  
        if (p[v] != 0) swap(u, v); 
        a[u].push_back({v, w});
        p[v] = u;
    }

    dp.assign(n + 1, vector<ll>(k + 1, -oo));
    dfs(1);

    ll res = dp[1][k];
    cout << (res == -oo ? 0 : res) << el;

    return 0;
}