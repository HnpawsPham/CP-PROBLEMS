#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>

int n, m, k;

void inp(vector<vi>& t, int n){
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin>>u>>v;
        t.push_back({u, v});
    }
    return;
}

int dfs(int u, int parent, int dis, vector<vi>& a){
    if(dis > k) return 0;
    int cnt = 1;

    for(const int& v : a[u])
        if(v != parent)
            cnt += dfs(v, u, dis + 1, a);

    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;

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

    int maxx = 0;
    for(int i = 0; i < m; i++){
        int x = dfs(i, -1, 1, a2);
        maxx = max(maxx, x);
    }

    vi res(n);
    for(int i = 0; i < n; i++){
        int x = dfs(i, -1, 0, a1);
        res[i] = x + maxx;
    }

    for(const int& x : res) cout<<x<<" ";
    return 0;
}