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

int n, st, en;
const int maxn = 2e5 + 5;
vi a[maxn], path;
bool check[maxn];
int h[maxn], p[maxn], s[maxn];

bool findpath(int u, int parent){
    path.push_back(u);
    if(u == en) return 1;

    for(int v : a[u]){
        if(v == parent) continue;
        if(findpath(v, u)) return 1;
    }
    path.pop_back();
    return 0;
}

int dfs(int u, int parent){
    int maxx = 0;
    for(int v : a[u]){
        if(v == parent || check[v]) continue;
        maxx = max(maxx, dfs(v, u) + 1);
    }
    return maxx;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
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
    cin>>st>>en;

    findpath(st, 0);
    memset(check, 0, sizeof check);
    memset(h, 0, sizeof h);
    
    int m = path.size();
    for(int i = 1; i <= m; i++)
        check[path[i - 1]] = 1;

    for(int i = 1; i <= m; i++)
        h[i] = dfs(path[i - 1], 0);
        
    p[0] = s[m + 1] = 0;
    for(int i = 1; i <= m; i++)
        p[i] = max(p[i - 1], i + h[i]);

    for(int i = m; i > 0; i--)
        s[i] = max(s[i + 1], m - i + 1 + h[i]);

    int res = 0;
    for(int i = 1; i < m; i++)
        res = max(res, min(p[i], s[i + 1]));
    cout<<res;
    return 0;
}