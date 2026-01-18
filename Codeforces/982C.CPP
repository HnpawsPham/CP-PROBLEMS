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

int n, cnt = 0;
bool ok = 1;
const int maxn = 1e5 + 5;
vi a[maxn];

int dfs(int u, int parent){
    int cntu = 1;
    for(int v : a[u]){
        if(v == parent) continue;
        int cntv = dfs(v, u);

        if(cntv % 2 == 0)
            cnt++; // +1 del ed
        else cntu += cntv; // combine components
    }
    return cntu;
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

    if(n & 1) return cout<<-1, 0;

    dfs(1, 0);
    cout<<cnt;
    return 0;
}