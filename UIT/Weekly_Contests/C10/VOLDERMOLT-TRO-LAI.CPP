#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll N, M, K;
vector<ll> a[505]; 
vector<ll> disc, low;
vector<bool> check;
vector<ll> parent;
ll timer;
ll bridge;

void dfs(ll u) {
    check[u] = true;
    disc[u] = low[u] = ++timer;

    for (ll v : a[u]) {
        if (v == parent[u]) 
            continue;

        if (check[v]) {
            low[u] = min(low[u], disc[v]);
        }
        else {
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u]) {
                bridge++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    for (ll i = 0; i < M; ++i) {
        ll u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    check.assign(N + 1, false);
    disc.assign(N + 1, -1);
    low.assign(N + 1, -1);
    parent.assign(N + 1, -1);
    timer = 0;
    bridge = 0;
    
    dfs(1);

    for (ll i = 1; i <= N; ++i) 
        if (!check[i]) return cout<<-1, 0;

    if (bridge > 0) return cout<<-1, 0;

    ll lim = M - N + 1;;
    ll rate = min(K, lim);
    ll res = (M + rate - 1) / rate;
    cout << res;
    return 0;
}