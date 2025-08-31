#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m;
const int maxn = 102;
int parent[maxn], sz[maxn];

void make_set(){
    for(int i = 0; i < n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
    return;
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool unite(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return 0;
    if(sz[a] < sz[b]) swap(a, b);

    sz[a] += sz[b];
    parent[b] = a;
    return 1;
}

bool comp(vi& a, vi& b){
    return a[2] < b[2];
}

int kruskal(const vector<vi>& ed, int must, int del){
    int msz = 0, d = 0;
    make_set();

    if(must != -1){
        d += ed[must][2];
        unite(ed[must][0], ed[must][1]);
        msz++;
    }

    for(int i = 0; i < m; i++){
        if(i == must || i == del) continue;
        int u = ed[i][0], v = ed[i][1], w = ed[i][2];

        if(unite(u, v)){
            msz++;
            d += w;
        }
        if(msz == n - 1) break;
    }

    if(msz != n - 1) return INT_MAX;
    return d;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    vector<vi> ed(m);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        ed[i] = {u, v, w};
    }

    for(int i = 0; i < m; i++)
        ed[i].push_back(i);

    sort(ed.begin(), ed.end(), comp);

    int ori = kruskal(ed, -1, -1);
    vector<vi> res(2);

    for(int i = 0; i < m; i++){
        if(kruskal(ed, -1, i) > ori) 
            res[0].push_back(ed[i][3]);

        else if(kruskal(ed, i, -1) == ori) 
            res[1].push_back(ed[i][3]);
    }

    for(auto v : res){
        for(int x : v) cout<<x<<" ";
        cout<<el;
    }
    return 0;
}

// 5 7
// 0 1 1
// 1 2 1
// 2 3 2
// 0 3 2
// 0 4 3
// 3 4 3
// 1 4 6