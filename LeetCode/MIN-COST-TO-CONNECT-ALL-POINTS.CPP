#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>

struct line{
    int u, v, w;
    line(int u1, int v1, int w1) : u(u1), v(v1), w(w1) {} 
};

int n;
vector<line> a;
vi parent, sz;
const int maxn = 1e6;

bool comp(const line& a, const line& b){
    return a.w < b.w;
}

void make_set(){
    parent.resize(maxn);
    sz.assign(maxn, 0);

    for(int i = 0; i < maxn; i++)
        parent[i] = i;
    return;
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool union_set(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return 0;
    if(sz[a] < sz[b]) swap(a, b);
    
    sz[a] += sz[b];
    sz[b] = 0;
    parent[b] = a;

    return 1;
}

int kruskal(){
    sort(a.begin(), a.end(), comp);
    int msz = 0, m = a.size(), d = 0;

    for(int i = 0; i < m; i++){
        if(msz == n - 1) break;

        if(union_set(a[i].u, a[i].v)){
            d += a[i].w;
            msz++;
        }
    }

    return d;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vector<vi> point(n);
    for(int i = 0; i < n; i++){
        int x, y;
        cin>>x>>y;
        point[i] = {x, y};
    }

    make_set();

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i != j){
                int w = abs(point[i][0] - point[j][0]) + abs(point[i][1] - point[j][1]);
                line l = {i, j, w};
                a.push_back(l);
            }
    cout<<kruskal();
    return 0;
}

// 5
// 0 0
// 2 2
// 3 10
// 5 2
// 7 0