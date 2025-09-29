#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;
const int maxn = 1e5 + 5;
int parent[maxn], sz[maxn];

void makeset(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
    return;
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);

    sz[a] += sz[b];
    sz[b] = 0;
    parent[b] = a;
    return;
}

bool lucky(int x){
    while(x > 0){
        if(x % 10 != 4 && x % 10 != 7) return 0;
        x /= 10;
    }
    return 1;
}

// nAk
ll A2(int x){
    return 1LL * x * (x - 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    makeset();
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin>>u>>v>>w;
        if(!lucky(w)) unite(u, v);
    }

    ll res = 0;
    for(int i = 1; i <= n; i++)
        res += 1LL * sz[i] * A2(n - sz[i]);
    
    cout<<res;
    return 0;
}