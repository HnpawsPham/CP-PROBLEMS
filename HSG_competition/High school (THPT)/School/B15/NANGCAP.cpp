#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int, int>

int n, m, sum;
const int maxn = 10005;
vector<vector<pii>> a(maxn);
bool check[maxn];
int parent[maxn];

void dfs(int u){
    check[u] = 1;

    for(pii x : a[u]){
        int v = x.second;
        
        if(!check[v]){
            parent[v] = u;
            dfs(v);
        }
        else if(check[v]){
            int minn = INT_MAX;
            int en = v, st = u;
            while(en != st){
                minn = min(minn, cur.second);
            }
        }
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

    return 0;
}