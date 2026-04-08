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
const int maxn = 1e5 + 5;
const int MOD = 1e9 + 7;
vi a[maxn];
int cnt[maxn] = {0};
bool check[maxn] = {0};

int dfs(int u){
    if(u == n) return 1;
    if(check[u]) return cnt[u];
    check[u] = 1;

    int res = 0;
    for(int v : a[u])
        res = (res + dfs(v)) % MOD;
    
    return cnt[u] = res;
}
int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    while(m--){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
    }
    cout<<dfs(1);
    return 0;
}

// 4 5
// 1 2
// 2 4
// 1 3
// 3 4
// 1 4