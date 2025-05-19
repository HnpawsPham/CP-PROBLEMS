#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

struct branch{
    int l, r, w;
    branch(int l1, int r1, int w1) : l(l1), r(r1), w(w1) {};

    bool operator<(const branch& other){
        return w > other.w;
    }
};

int n, q;
const int maxn = 105;
const int oo = 2e6;
vector<branch> a;
vector<vector<ll>> dp(maxn, vector<ll>(maxn, -oo));

void dfs(int u){
    int l = a[u].r, r = a[u].r, w = a[u].w;

    
    return;
}

int main(){
    // freopen("APPLE.inp", "r", stdin);
    // freopen("APPLE.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin>>u>>v>>w;
        a.push_back(branch(u, v, w));
    }   

    dfs(0);

    ll res = dp[0][q];
    cout<<(res != -oo ? res : 0);
    return 0;
}