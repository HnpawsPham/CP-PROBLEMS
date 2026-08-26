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
#define taskname "BEAUTY"

int n, k;
const int maxn = 1e5 + 5;
vi a[maxn];
int mid = -1, maxx = 0;

void dfs(int u, int parent, int d){
    if(d > maxx){
        maxx = d;
        mid = u;
    }

    for(int v : a[u]){
        if(v == parent) continue;
        dfs(v, u, d + 1);
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

    cin>>n>>k;
    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dfs(1, 0, 0);
    int dia = maxx;
    maxx = 0;
    mid = -1;
    dfs(mid, 0, 0);
    dia += maxx;

    if(dia < k) cout<<n - 1;
    else cout<<dia - 1 - (dia % 2);
    return 0;
}