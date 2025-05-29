#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>

int n, m;

void inp(vector<vi>& t, int n){
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin>>u>>v;
        t.push_back({u, v});
    }
    return;
}

// sub1 dfs
// int dfs(int u, int parent, int dis, bool is_odd, vector<vi>& a){
//     int cnt = (dis % 2 == is_odd);

//     for(const int& v : a[u])
//         if(v != parent)
//             cnt += dfs(v, u, dis + 1, is_odd, a);
    
//     return cnt;
// }

// depth[u] % 2 == depth[v] % 2 => d(u, v) % 2 == 0
void dfs(int u, int parent, int dis, int& even, vector<bool>& depth, vector<vi>& a){
    depth[u] = (dis % 2 == 0);
    even += depth[u];

    for(const int& v : a[u])
        if(v != parent)
            dfs(v, u, dis + 1, even, depth, a);
    
    return;
}

void dfs2(int u, int parent, int dis, int& even, vector<vi>& a){
    even += (dis % 2);

    for(const int& v : a[u])
        if(v != parent)
            dfs2(v, u, dis + 1, even, a);
    
    return;
}

// void sub1(vi& res){
//     int maxx = 0;
//     for(int i = 0; i < m; i++)
//         maxx = max(maxx, dfs(i, -1, 1, 1, a2));

//     vi res(n);
//     for(int i = 0; i < n; i++)
//         res[i] = dfs(i, -1, 0, 0, a1) + maxx;
//     return;
// }

void sub2(vi& res, vector<vi>& a1, vector<vi>& a2){
    vector<bool> depth(n);

    int even1, odd1, even2, odd2;
    even1 = even2 = 0;

    dfs(0, -1, 0, even1, depth, a1);
    odd1 = n - even1;

    dfs2(0, -1, 0, even2, a2);
    odd2 = m - even2;

    for(int i = 0; i < n; i++){
        if(depth[i]) res[i] = even1 + max(even2, odd2);
        else res[i] = odd1 + max(even2, odd2);
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    vector<vi> t1, t2;
    inp(t1, n);
    inp(t2, m);

    vector<vi> a1(n);
    vector<vi> a2(m);

    for(const vi& v : t1){
        a1[v[0]].push_back(v[1]);
        a1[v[1]].push_back(v[0]);
    }

    for(const vi& v : t2){
        a2[v[0]].push_back(v[1]);
        a2[v[1]].push_back(v[0]);
    }
    vi res(n);
    // sub1(res);
    sub2(res, a1, a2);
    for(int x : res) cout<<x<<" ";
    return 0;
}