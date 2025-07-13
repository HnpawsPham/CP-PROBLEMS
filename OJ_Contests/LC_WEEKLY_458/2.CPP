#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'
#define pii pair<int, int>
#define vi vector<int>
#define fi first
#define se second

int n, k;
vi parent, sz;

void make_set(){
    parent.resize(n);
    sz.assign(n, 1);

    for(int i = 0; i < n; i++){
        parent[i] = i;
    }
    return;
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void union_set(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];
    sz[b] = 0;
    return;
}

bool check(int t, int k, vector<vi>& a){
    make_set();

    int cnt = 0;
    for(const vi& v : a){
        if(v[2] <= t) 
            union_set(v[0], v[1]);
    }
    for(int i = 0; i < n; i++)
        if(sz[i]) cnt++;

    return cnt <= k;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    vector<vi> a;
    int maxx = 0;
    for(int i = 0; i < n - 1; i++){
        int u, v, w;
        cin>>u>>v>>w;
        a.push_back({u, v, w});
        maxx = max(maxx, w);
    }

    int l = 0, r = maxx, mid;
    while(l <= r){
        mid = (l + r) / 2;
        if(check(mid, k, a)) r = mid - 1;
        else l = mid + 1;
    }
    cout<<l;

    return 0;
}