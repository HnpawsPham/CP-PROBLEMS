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

int n, furthest = 0;
const int maxn = 3e5 + 5;
vi a[maxn];
int dis[maxn][2];

void dfs(int i, int u, int parent){
    if(dis[u][i] > dis[furthest][i]) 
        furthest = u;

    for(int v : a[u]){
        if(v == parent) continue;
        dis[v][i] = dis[u][i] + 1;
        dfs(i, v, u);
    }
    return;
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

    if(n == 1) return cout<<1, 0;

    memset(dis, 0, sizeof dis);
    dfs(0, 1, 0);
    memset(dis, 0, sizeof dis);
    dfs(0, furthest, 0);
    dfs(1, furthest, 0);
    
    for(int i = 1; i <= n; i++)
        cout<<(max(dis[furthest][1], max(dis[i][0], dis[i][1]) + 1))<<el;
    return 0;
}