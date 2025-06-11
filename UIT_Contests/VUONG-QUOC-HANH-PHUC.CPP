#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>

int n, m;
const int maxn = 5005;
vi a[maxn];
int sz[maxn], parent[maxn];

void make_set(){
    for(int i = 1; i <= n; i++){
        sz[i] = 1;
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
    if(a < b) swap(a, b);

    sz[a] += sz[b];
    sz[b] = 0;
    parent[b] = a;

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    make_set();

    while(m--){
        int u, v;
        cin>>u>>v;
        union_set(u, v);
    }

    int cnt = -1;
    for(int i = 1; i <= n; i++)
        if(sz[i] > 0) cnt++;

    cout<<cnt;
    return 0;
}