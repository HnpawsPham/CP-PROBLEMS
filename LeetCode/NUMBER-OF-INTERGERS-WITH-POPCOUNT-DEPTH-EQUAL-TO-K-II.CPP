#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

int n, m;

int depth(ll x){
    int cnt = 0;
    while(x > 1){
        x = __builtin_popcountll(x);
        cnt++;
    }
    return cnt;
}

void update(vi& bit, int i, int val){
    while(i <= n){
        bit[i] += val;
        i += (i & -i);
    }
    return;
}

int query(vi& bit, int i){
    int res = 0;
    
    while(i > 0){
        res += bit[i];
        i -= (i & -i);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    vll a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<vll> q(m);
    for(int i = 0; i < m; i++){
        int opt, x, y;
        cin>>opt>>x>>y;
        q[i] = {opt, x, y};
        if(opt == 1) {
            ll k;
            cin>>k;
            q[i].push_back(k);
        }
    }
    
    // main
    vector<vi> bit(6, vi(n + 2, 0));

    for(int i = 0; i < n; i++){
        int d = depth(a[i]);
        update(bit[d], i + 1, 1);
    }

    vi res;
    for(const vll& v : q){
        if(v[0] == 1){
            int l = v[1], r = v[2], k = v[3];
            int x = query(bit[k], r + 1) - query(bit[k], l);
            res.push_back(x); 
        }
        else{
            int i = v[1]; ll val = v[2];
            update(bit[depth(a[i])], i + 1, -1);
            
            a[i] = val;
            update(bit[depth(a[i])], i + 1, 1);
        }
    }
    for(int x : res) cout<<x<<" ";
    return 0;
}

// 2 3
// 2 4
// 1 0 1 1
// 2 1 1
// 1 0 1 0

// 3 4
// 3 5 6
// 1 0 2 2
// 2 1 4
// 1 1 2 1
// 1 0 1 0
