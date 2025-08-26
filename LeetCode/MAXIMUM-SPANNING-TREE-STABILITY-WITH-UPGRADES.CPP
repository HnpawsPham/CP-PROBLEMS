#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

struct line{
    int u, v, w, must;
    line(int u1, int v1, int w1, int must1) : u(u1), v(v1), w(w1), must(must1) {};
};

int n, m, k;
const int maxn = 1e5 + 5;
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

bool union_set(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return 0;
    if(sz[a] < sz[b]) swap(a, b);

    sz[a] += sz[b];
    parent[b] = a;
    return 1;
}

bool comp(const vi& a, const vi& b){
    return a[2] > b[2];
}

bool kruskal(int t, const vector<vi>& a){
    int msz = 0, upgrade = 0;

    for(const auto& vt : a){
        int u = vt[0], v = vt[1], w = vt[2], must = vt[3];
        if(must){
            if(w < t) return 0;
            if(!union_set(u, v)) return 0;
            msz++;
            continue;
        }
    }
    for(const auto& vt : a){
        int u = vt[0], v = vt[1], w = vt[2], must = vt[3];
        if(must) continue;

        if(2 * w >= t && union_set(u, v)){
            msz++;
            if(w < t) upgrade++;
            if(upgrade > k) return 0;
            if(msz == n - 1) break;
        }
    }
    return msz == n - 1; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    vector<vi> ed(m, vi(4));
    for(int i = 0; i < m; i++)
        cin>>ed[i][0]>>ed[i][1]>>ed[i][2]>>ed[i][3];
    
    make_set();
    sort(ed.begin(), ed.end(), comp);

    int l = 1, r = maxn, mid, res;
    while(l <= r){
        mid = (l + r) / 2;
        if(kruskal(mid, ed)) {
            l = mid + 1;
            res = mid;
        }
        else r = mid - 1;
    }
    cout<<res;
    return 0;
}

// 3 2 1
// 0 1 2 1
// 1 2 3 0

// 3 3 2
// 0 1 4 0
// 1 2 3 0
// 0 2 1 0