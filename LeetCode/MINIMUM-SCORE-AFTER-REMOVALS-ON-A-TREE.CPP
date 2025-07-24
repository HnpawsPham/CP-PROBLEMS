#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>

int n, total = 0, res = INT_MAX;
vector<vi> a;

int score(int x, int y, int z){
    return max({x, y, z}) - min({x, y, z});
}

int dfs1(int u, int parent, int grandparent, int xor1, vi& val){
    int xor2 = val[u];

    for(int v : a[u]){
        if(v == parent) continue;
        xor2 ^= dfs1(v, u, grandparent, xor1, val);
    }

    if(parent != grandparent){
        int xor3 = total ^ xor1 ^ xor2;
        res = min(res, score(xor1, xor2, xor3));
    }
    return xor2;
}


int dfs(int u, int parent, vi& val){
    int xor1 = val[u];

    for(int v : a[u]){
        if(v == parent) continue;
        xor1 ^= dfs(v, u, val);
    }

    if(parent != -1)
        dfs1(parent, u, u, xor1, val);
    
    return xor1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vi val(n);
    for(int i = 0; i < n; i++) cin>>val[i];

    vector<vi> ed(n - 1);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin>>u>>v;
        ed[i] = {u, v};
    }

    // build tree
    a.resize(n);

    for(const vi& v : ed){
        a[v[0]].push_back(v[1]);
        a[v[1]].push_back(v[0]);
    }

    for(int x : val) total ^= x;
    dfs(0, -1, val);

    cout<<res;
    return 0;
}

// 5
// 1 5 5 4 11
// 0 1
// 1 2
// 1 3
// 3 4