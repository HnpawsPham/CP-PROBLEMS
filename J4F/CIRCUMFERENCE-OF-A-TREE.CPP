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

int n, maxdis = 0, g;
const int maxn = 3e5 + 5;
vi a[maxn];

void dfs(int u, int parent, int dis){
    if(dis > maxdis){
        maxdis = dis;
        g = u;
    }
    for(int v : a[u]){
        if(v == parent) continue;
        dfs(v, u, dis + 1);
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

    int tmp;
    dfs(1, 0, 0);
    tmp = g;

    maxdis = 0;
    dfs(tmp, 0, 0);
    cout<<maxdis * 3;
    return 0;
}