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
const int maxn = 105;
int parent[maxn], sz[maxn];

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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    pii a[n];
    for(int i = 0; i < n; i++) {
        cin>>a[i].fi>>a[i].se;
        parent[i] = i;
        sz[i] = 1;
    }

    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(a[i].fi == a[j].fi || a[i].se == a[j].se)
                unite(i, j);

    int cnt = 0;
    for(int i = 0; i < n; i++)
        if(sz[i]) cnt++;
    cout<<cnt - 1;
    return 0;
}