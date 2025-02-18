#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int, int>

int n, m, sum;
const int maxn = 10005;
vector<vector<pii>> a(maxn);
bool check[maxn];
bool ok = 0;
vector<pii> c;

void dfs(int u, int minn, pii minc){
    check[u] = 1;

    for(pii x : a[u]){
        int w = x.first;
        int v = x.second;

        if(!check[v]) {
            dfs(v, minn, minc);
        }
        else {
            if(w < minn){
                minn = w;
                minc = {u, v};
            }
            ok = 1;
        }
    }

    if(ok){
        auto it = find(c.begin(), c.end(), minc);

        if(it != c.end()) return;
        sum += minn;
        ok = 0;
        c.push_back(minc);
    }
    return;
}

int main(){
    freopen(".\\txt\\NANGCAP.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;

        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }
    dfs(1, INT_MAX, {0, 0});
    cout<<sum<<el;

    return 0;
}