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
vi a[maxn];
bool check = 1;
int color[maxn];

void dfs(int u, int x){
    color[u] = x;
    for(int v : a[u]){
        if(color[v] == 0)
            dfs(v, 3 - x);
        else if(color[v] == x)
            check = 0;
    }
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
        a[v].push_back(u);
    }
    memset(color, 0, sizeof color);
    for(int i = 1; i <= n; i++)
        if(!color[i]) dfs(i, 1);

    if(!check) return cout<<-1, 0;

    vi gr1, gr2;
    for(int i = 1; i <= n; i++)
        if(color[i] == 1) gr1.push_back(i);
        else gr2.push_back(i);

    cout<<gr1.size()<<el;
    for(const int& x : gr1) cout<<x<<" ";
    cout<<el<<gr2.size()<<el;
    for(const int& x : gr2) cout<<x<<" ";
    return 0;
}
