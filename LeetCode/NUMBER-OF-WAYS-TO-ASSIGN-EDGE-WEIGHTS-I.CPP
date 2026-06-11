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

int n, maxh = 0;
const int maxn = 1e5 + 5;
const int MOD = 1e9 + 7;
vi a[maxn];

int ppow(int a, int b){
    if(b == 0) return 1;
    int half = ppow(a, b / 2);
    if(b & 1) return 1LL * half * 1LL * half % MOD * 1LL * a % MOD;
    return 1LL * half * 1LL *  half % MOD;
}

void dfs(int u, int h, int parent){
    for(int v : a[u]){
        if(v == parent) continue;
        dfs(v, h + 1, u);
    }
    maxh = max(maxh, h);
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
    dfs(1, 0, 0);
    cout<<ppow(2, maxh - 1)<<el;
    return 0;
}

// 2
// 1 2

// 5
// 1 2
// 1 3
// 3 4
// 3 5