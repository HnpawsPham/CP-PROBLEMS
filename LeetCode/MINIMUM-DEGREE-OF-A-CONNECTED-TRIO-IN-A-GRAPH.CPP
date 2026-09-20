#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""

int n, m;
const int maxn = 405;
vi a[maxn];
int deg[maxn];
unordered_set<int> child[maxn];

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    memset(deg, 0, sizeof deg);
    while(m--){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
        child[u].insert(v);
        child[v].insert(u);
        deg[u]++;
        deg[v]++;
    }

    int res = n * n;
    for(int u = 1; u <= n; u++)
        for(int v : a[u])
            for(int x : a[v]){
                if(x == u || !child[u].count(x)) continue;
                res = min(res, deg[u] + deg[v] + deg[x] - 6);
            }
    cout<<res;
    return 0;
}

// 6 6
// 1 2
// 1 3
// 3 2
// 4 1
// 5 2
// 3 6

// 7 8
// 1 3
// 4 1
// 4 3
// 2 5
// 5 6
// 6 7
// 7 5
// 2 6